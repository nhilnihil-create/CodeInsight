#include "bits/stdc++.h"
using namespace std;
#define ll long long int
#define rep(i,n) for( int i = 0; i < n; i++ )
#define rrep(i,n) for( int i = n; i >= 0; i-- )
#define REP(i,s,t) for( int i = s; i <= t; i++ )
#define RREP(i,s,t) for( int i = s; i >= t; i-- )
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define INF 2000000000
#define mod 1000000007
#define INF2 1000000000000000000
#define int long long
vector<int> G[100010];
int N, K;

int dfs(int v, int p) {
    int num;
    if (p == -1) num = K - 1;
    else num = K - 2;
    int case_num = 1;
    for(auto to : G[v]) {
        if (to == p) continue;
        case_num *= num;
        num--;
        case_num %= mod;
    }
    for(auto to: G[v]) {
        if (to == p) continue;
        case_num *= dfs(to, v);
        case_num %= mod;
    }
    return case_num;
}

signed main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N >> K;
    rep(i, N - 1) {
        int s, t;
        cin >> s >> t;
        s--; t--;
        G[s].push_back(t);
        G[t].push_back(s);
    }
    cout << K * dfs(0, -1) % mod << endl;

    return 0;
}
