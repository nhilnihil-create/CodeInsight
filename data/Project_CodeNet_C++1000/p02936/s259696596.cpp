#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define INF 100000000
#define rep(i,s,n) for (int i = (int)(s); i < (int)(n); i++)
#define mp make_pair
ll mod = 1000000007;
ll mod2 = 998244353;
vector<vector<int>> G(404040); 
vector<int> score(404040,0);
vector<int> ans(404040,-1);

int dfs(int x,int sum){
    if (ans[x]!=-1) return 0;
    sum+=score[x];
    ans[x] = sum;
    for (auto nex : G[x]){
        dfs(nex,sum);
    }
    return 0;
}

int main(){
	int n,q;cin>>n>>q;
    rep(i,0,n-1){
        int a,b;cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    rep(i,0,q){
        int p,x;cin>>p>>x;
        score[p]+=x;
    }
    dfs(1,0);
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<endl;
    }
}