#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()


vector<vector<pair<int,int>>> G(100010);
int n;
int ans[100010];

void dfs(int cu,int pa=-1,int col=0){
    set<int> used;
    used.insert(col);
    int c=1;
    for(auto to : G[cu]){
        if(to.first==pa) continue;
        while(used.count(c)) c++;
        ans[to.second]=c;
        dfs(to.first,cu,c);
        c++;
    }
}

int main(){
    cin>>n;
    G.resize(n);

    rep(i,n-1){
        int a,b;
        cin>>a>>b;
        a--,b--;
        G[a].push_back({b,i});
        G[b].push_back({a,i});
    }

    dfs(0);
    int ma=0;
    rep(i,n) ma=max(ma,(int)G[i].size());
    cout<<ma<<endl;
    rep(i,n-1) cout<<ans[i]<<endl;

}