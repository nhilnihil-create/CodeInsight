#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int nums[100001];
vector<int> adj[100001];

int main()
{
    int n,m,a,b;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>nums[i];
    }
    while(m--){
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    int cnt = 0;
    for(int i=1;i<=n;i++){
        bool flag = true;
        if(adj[i].size()>0){
            for(int child:adj[i]){
                if(nums[child]>=nums[i]){
                    flag = false;
                    break;
                }
            }
        }
        if(flag){
            cnt++;
        }
    }
    cout<<cnt;
}
