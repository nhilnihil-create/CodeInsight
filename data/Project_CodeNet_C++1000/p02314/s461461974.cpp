
#include<iostream>
using namespace std;
int main(){
    int n,m,t;
    int c[21];
    int T[21][100001];
    cin>>n>>m;
    int counter=0;
    for(int k=0;k<m;++k){
        cin>>t;
        c[k]=t;
        if(c[k]>n){
            c[k]=c[k+1];
            counter++;
        }
        for(int j=1;j<=n;++j){
            T[k][0]=0;
            T[0][j]=100000;
        }
    }
    int m1=m-counter;
    for(int i=1;i<=m1;++i){
        for(int j=1;j<=n;++j){
            if(c[i-1]<=j){
                T[i][j]=min(T[i-1][j],T[i][j-c[i-1]]+1);
                }
            else
                T[i][j]=T[i-1][j];
                
        }
    }
    cout<<T[m1][n]<<endl;
}