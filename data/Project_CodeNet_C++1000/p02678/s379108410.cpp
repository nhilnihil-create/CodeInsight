#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
const int mod = 1e6;

vector<vii> adjlist;

main(){
    int n,m;
    cin>>n>>m;
    int a,b;
    adjlist.assign(n+1,vii());
    while(m--){
        cin>>a>>b;
        adjlist[a].push_back(ii(b,1));
        adjlist[b].push_back(ii(a,1));
    }
    queue<int>q; q.push(1);
    vector<int> ans(n+1,mod);
    while(!q.empty()){
        int u = q.front();q.pop();
        for(int i=0;i<adjlist[u].size();i++){
            ii v = adjlist[u][i];
            if(ans[v.first] == mod){
                ans[v.first] = u;
                q.push(v.first);
            }
        }
    }
    cout<<"Yes"<<"\n";
    for(int i=2;i<=n;i++) cout<<ans[i]<<'\n';
}