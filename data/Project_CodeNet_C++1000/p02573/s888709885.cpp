#include <bits/stdc++.h>
#include <iomanip>
#define M 100000
#define MAX 1000000001
#define MIN -10000000000000000
#define mod 1000000007
#define ss second
#define ff first
#define ll long long int
#define pb push_back
#define ld double
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;

int solve(set<int>adj[],int current,int parent,bool vis[]){
    int ans = 0;
    vis[current] = 1;
    for(int i:adj[current]){
        if(i != parent){
            if(vis[i] == 0){
                ans += solve(adj,i,current,vis);
            }
        }
    }
    ans ++;

    return ans;
}

int main(){
    int n,m;
    cin>>n>>m;
    set<int>adj[n+1];
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].insert(b);
        adj[b].insert(a);
    }
    int mx = 0;
    bool vis[n+1] = {0};
    for(int i=1;i<=n;i++){
        if(vis[i] == 0){
            mx = max(mx,solve(adj,i,0,vis));
        }
    }
    // mx--;
    cout<<mx<<"\n";
    return 0;
        
}
