#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define pb push_back
const int maxn = 10000;
const int INF32 = 1'050'000'000;
const long long INF64 = 4'000'000'000'000'000'000;
const int MOD7 = 1'000'000'007;
const int MOD9 = 1'000'000'009;
const int mod = MOD7;

void ERROR(int num) { cout << "ERROR" << num << endl; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
int dx[8]={-1,0,1,0,1,1,-1,-1};
int dy[8]={0,-1,0,1,1,-1,1,-1};


struct P
{
    int num;
    int id;    
};
vector<vector<P>> G;
vector<int> ans;

void dfs(int cur, int color, int from){
    //cout << "cur: " << cur << endl;
    int n_color = 1;
    rep(i,G[cur].size()){
        int nx = G[cur][i].num;
        int id = G[cur][i].id;
        if(nx==from) continue; //防止回去
        if(n_color==color) n_color++; //颜色不能重复
        ans[id] = n_color; n_color++;
        dfs(nx, ans[id], cur);
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int N;
    cin >> N;
    G.resize(N);
    rep(i,N-1){
        int a, b;
        cin >> a >> b;
        a--, b--;
        G[a].pb(P{b,i});
        G[b].pb(P{a,i});
    }

    ans.resize(N-1,-1);
    dfs(0,-1,-1);

    //rep(i,ans.size()) cout << ans[i] << " ";
    //cout << endl;

    int maxn = 0;
    rep(i,ans.size()) maxn = max(maxn,ans[i]);
    cout << maxn << endl;
    rep(i,ans.size()) cout << ans[i] << endl;

}