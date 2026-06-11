#include <bits/stdc++.h>
using namespace std;
#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
typedef long long ll;
const long long INF = 1LL << 60;
const long long MOD = 1e9 + 7;
const int MAX_V = 200000;
typedef pair<int, int> P;
int N, K;
ll ans = 0;
vector<vector<int>> G(MAX_V);
vector<bool> check(MAX_V);

void dfs(int v, int d) {
    ll c = K - 1;
    check[v] = true;
    if (d >= 1) c--;
    for (int to : G[v]) {
        if (check[to]) continue;
        ans *= c;
        ans %= MOD;
        c--;
        dfs(to, d + 1);
    }
}

int main()
{
    cin >> N >> K;
    rep(i, N - 1) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    
    ans = K;
    dfs(0, 0);

    cout << ans << endl;
    return 0;
}