#include <bits/stdc++.h>
using namespace std;
#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
typedef long long ll;
const long long INF = 1LL << 60;
typedef pair<int, int> P;
const long long MOD = 1e9 + 7;
vector<vector<int>> G;

ll ans;
ll N, K;
void dfs(int s, int b, ll num) {
    ans *= num;
    ans %= MOD;
    ll k = K - 1;
    if (b >= 0) k--;
    rep(i, G[s].size()) {
        if (G[s][i] == b) continue;
        dfs(G[s][i], s, k);
        k--;
    }
}
int main()
{
    cin >> N >> K;
    G = vector<vector<int>>(N);

    int s;
    rep(i, N - 1) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
        s = a;
    }

    ans = 1;
    dfs(s, -1, K);
    cout << ans << endl;
    return 0;
}