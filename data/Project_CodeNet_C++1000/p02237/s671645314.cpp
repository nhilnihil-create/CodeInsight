#include<iostream>
using namespace std;
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin>>N;
    int G[N][N]={};
    for(int i=0;i<N;++i){
        int u,k;
        cin>>u>>k;
        for(int j=0;j<k;++j){
            int v;
            cin>>v;
            G[u-1][v-1]=1;
        }
    }
    for(int i=0;i<N;++i){
        for(int j=0;j<N;++j){
            if(j) cout<<' ';
            cout<<G[i][j];
        }
        cout<<endl;
    }
}