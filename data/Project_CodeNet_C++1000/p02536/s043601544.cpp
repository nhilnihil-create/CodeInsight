#include<bits/stdc++.h>

using namespace std;

vector<bool> vis(100000,false);

void dfs(int u,vector<vector<int> > &v){
    vis[u]=true;
    for(auto i:v[u]){
        if(vis[i]==false){
            dfs(i,v);
        }
    }
}



int main(){
	#ifndef ONLINE_JUDGE  
    freopen("i.txt", "r", stdin); 
    freopen("o.txt", "w", stdout); 
    #endif
    int n,m;
    cin>>n>>m;
    vector<vector<int> > v(n+1);
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    int count=0;
    for(int i=1;i<=n;i++){
        if(vis[i]==false){
            count++;
            dfs(i,v);
        }
    }
    cout<<count-1<<endl;


}