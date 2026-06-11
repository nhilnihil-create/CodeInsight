#include<bits/stdc++.h>
using namespace std;

int dfs(int s, int arr[], vector<int> gra[]){
    int coun=1;
    arr[s]=1;
    for(int i:gra[s]){
        if(arr[i]==0){
            coun+=dfs(i,arr, gra);
        }
    }
    // cout<<"in dfs "<<s<<" "<<coun<<endl;
    return coun;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> graph[n+1];
    for(int i=0; i<m; i++){
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    int vis[n+1];
    for(int i=0; i<=n; i++)
        vis[i]=0;
    int max=0; 
    for(int i=1; i<n+1; i++){
        if(vis[i]==0){
            int t=dfs(i,vis,graph);
            // cout<<i<<" "<<t<<" "<<max<<endl;
            if(t>max)
                max=t;
        }
    }
    cout<<max<<endl;
    return 0;
}