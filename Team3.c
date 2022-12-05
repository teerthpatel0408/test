//Burhanuddin Murtaza Tinwala - 2021A7PS2905H
//Darshil Shah - 2021A7PS2817H

#include<stdio.h>
#include<stdlib.h>
int main(int argc , char*argv[]){
    FILE *myFile= fopen(argv[1],"r");//accessing file using command line arguement
    int n,e; 
    fscanf(myFile, "%d\n%d",&n,&e);// Scanning file for number of nodes and edges
    if(e>(n*(n-1))/2)//Chechking edge case of maximum possible edges .
    {
        printf("%s","Error : Number of edges exceed the number possible with the nodes");
        return 0;
    }
    int degree[n],adj_Matrix[n][n];
    for(int i=0; i<n; i++)//Initializing all array elements as 0
     degree[i]=0;
     for(int i=0; i<n; i++)
     for(int j=0; j<n; j++)
     adj_Matrix[i][j]=0;    //Initializing matrix as 0
     for(int i = 0; i < e; i++){//Traversing through all lines of edge relations
       if(feof(myFile)!=0){
        printf("%s\n","Error : Invalid Number of Edges Entry(With the given edges output is provided)");//Checking for number of edges provided
        break;}
        else{
       int row, col;
       fscanf(myFile,"%d %d", &row, &col);//Scanning file for edge relations
       if((row>n)||(col>n))
       {
        printf("%s\n","Error : Invalid Edge Entry");//Checking for valid entry
        return 0;
       }
       if((adj_Matrix[row-1][col-1]>0)||(adj_Matrix[col-1][row-1]>0))
       printf("%s\n","Error : Given graph consists a multiedge(Avoiding this multiedge , output is given )");
       else{
       adj_Matrix[row-1][col-1]++;
       adj_Matrix[col-1][row-1]++;
       degree[row-1]++;
       degree[col-1]++;
    }}}
    if(feof(myFile)==0)
    printf("%s%d%s\n","Error : Number of edges input exceeded (Considering only the first ",e," edges output is given)");
    int temp=0;
    for (int k = 0; k < n-1; ++k) //Sorting the array
    {
            for (int j =k + 1; j < n; ++j)
            {
 
                if (degree[k] < degree[j]) 
                {
                    temp =  degree[k];
                    degree[k] = degree[j];
                    degree[j] = temp;
                }
 
            }
   }
   for(int i=0; i<n; i++)//Checking for invalid nodes entry 
     if(degree[i]==0)
     printf("%s\n","Error : Invalid Nodes Entry(Considering the node as isolated node, output is given ");
  
    for(int i=0; i<n; i++)//Printing the array
    printf("%d ",degree[i]);
    // FILE *fp=fopen("output.txt","w");//Writing the output in output file
    // for(int i=0; i<n; i++)
    // {
    //     int ch=degree[i];
    //     fprintf(fp,"%d ", ch);
    // }
    printf("\n");
    return 0;
}