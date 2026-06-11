#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define erep(i, n) for (ll i = 0; i <= (ll)(n); ++i)
#define FOR(i,a,b) for (ll i = (a); i < (ll)(b); ++i)
#define EFOR(i,a,b) for (ll i = (a); i <= (ll)(b); ++i)

void chmax(ll& a, ll b) { a = max(a, b); }
void chmin(ll& a, ll b) { a = min(a, b); }

using P = pair<int, int>;

const int MAX_N = 1e5+5;
const int INF = 1001001001;

vector<int> a, ans;
vector<int> to[MAX_N];
int dp[MAX_N];

ll modnum = 1e9+7;

using Graph = vector<vector<int>>;
Graph G(MAX_N);

ll dfs(int k, int now, int from=-1) {
    if(k < G[now].size()) {
        // 色が足りない場合は作れない
        return 0;
    }

    
    int use_num;
    if(from == -1) {
        // 根だけは特別
        use_num = k-1;
    } else {
        use_num = k-2;
    }
    
    ll case_num=1;
    for(auto e : G[now]) {
        // 親には戻らない
        if(e == from) continue;

        // kPcを求める部分
        // kはuse_numでループ毎に-1していく
        // cは色の数でなく、この頂点からの子の数(つまりこの頂点からの辺から親への辺を引いた数ということ)
        case_num *= use_num;
        use_num--;
        case_num %= modnum;

        // さらに子へと進む
        case_num *= dfs(k, e, now);
        case_num %= modnum;
    }
    return case_num;
}

int main() {
    int n,k; cin >> n >> k;
    rep(i, n-1) {
        int a,b; cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    ll ans = k*dfs(k,0);
    ans %= modnum;
    cout << ans << endl;

    return 0;
}
