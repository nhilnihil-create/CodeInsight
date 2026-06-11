#include<bits/stdc++.h>

using namespace std;

int main(){
    int x,n;cin>>x>>n;
    bool visited[150];
    memset(visited,false,sizeof(visited));
    int u;
    for(int i=0;i<n;i++){
        cin>>u;
        visited[u]=true;
    }
    int smaller=x,larger=x;
    while(true){
        //cout <<smaller<<","<<larger<<":"<<visited[smaller]<<","<<visited[larger]<<endl;
        if(!visited[smaller]){
            cout <<smaller<<endl;
            return 0;
        }
        if(!visited[larger]){
            cout <<larger<<endl;
            return 0;
        }
        smaller--;
        larger++;
    }
}
