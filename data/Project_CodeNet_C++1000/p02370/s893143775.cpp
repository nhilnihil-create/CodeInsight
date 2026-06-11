#include<bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);i++)
#define ALL(v) (v).begin(),(v).end()
#define int long long
#define INF 1e18
using namespace std;

//-----------------------------------------------------------------------

int V,E;
vector<int> G[10005];
int indeg[10005];

vector<int> tsort()
{
    stack<int> S;
    REP(i,V) if(indeg[i]==0) S.push(i);

    vector<int> res;
    while(!S.empty()){
        int v=S.top(); S.pop();
        res.push_back(v);
        for(auto u:G[v]){
            indeg[u]--;
            if(indeg[u]==0) S.push(u);
        }
    }
    return res;
}

signed main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin>>V>>E;
    REP(i,E){
        int a,b; cin>>a>>b;
        G[a].push_back(b);
        indeg[b]++;
    }

    vector<int> ans=tsort();
    REP(i,ans.size()) cout<<ans[i]<<endl;

}

