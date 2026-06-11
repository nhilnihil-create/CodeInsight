#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

struct Node{
    int k;
    int* c;
    int p;
};

int main(void){
    int n,i,j,id,k,depth;
    Node node[100000];
    
    cin>>n;
    
    for(i=0;i<n;i++){
        node[i].p=-1;
    }
    
    for(i=0;i<n;i++){
        cin>>id;
        cin>>k;
        node[id].k=k;
        node[id].c=(int*)malloc(sizeof(int)*k);
        for(j=0;j<k;j++){
            cin>>node[id].c[j];
            node[node[id].c[j]].p=id;
        }
    }
    
    for(i=0;i<n;i++){
        id=i;
        k=node[i].k;
        depth=0;
        while(node[id].p!=-1){
            id=node[id].p;
            depth++;
        }

        printf("node %d: parent = %d, depth = %d, ",i,node[i].p,depth);
        if(node[i].p==-1){
            printf("root, ");
            
            if(k==0){
                printf("[]\n");
                return 0;
            }
            
            printf("[");
            for(j=0;j<k-1;j++){
                printf("%d, ",node[i].c[j]);
            }
            printf("%d]",node[i].c[k-1]);
        }
        else if(k>0){
            printf("internal node, ");
            printf("[");
            for(j=0;j<node[i].k-1;j++){
                printf("%d, ",node[i].c[j]);
            }
            printf("%d]",node[i].c[k-1]);
        }
        else{
            printf("leaf, []");
        }
        printf("\n");
    }
    
    return 0;
}
