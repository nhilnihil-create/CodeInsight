#include <iostream>
using namespace std;

int main(){
    long n,m,l,i,j,k,s,t,u,v;
    long A[1000][1000]={},B[1000][1000]={},C[1000][1000];
    cin>>n>>m>>l;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            cin>>A[i][j];
        }
    }
    for(k=0;k<m;k++){
        for(s=0;s<l;s++){
            cin>>B[k][s];
        }
    }
    for(t=0;t<n;t++){
        for(u=0;u<l;u++){
            for(v=0;v<m;v++){
                C[t][u]+=A[t][v]*B[v][u];
            }
            if(u==l-1){
                cout<<C[t][u];
            }else{
                cout<<C[t][u]<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
    
}

