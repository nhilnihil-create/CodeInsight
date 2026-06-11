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
typedef pair<int, int> P;
int main()
{
    int N, K;
    cin >> N >> K;

    vector<vector<int>> G(N);
    rep(i, N - 1) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    ll ans = K;
    queue<P> que;
    que.push({0, 0});
    int deep = 0;
    while (!que.empty()) {
        int v = que.front().first, p = que.front().second;
        que.pop();
        ll cnt = 0;
        rep(i, G[v].size()) {
            if (G[v][i] == p) continue;
            que.push({G[v][i], v});
            cnt++;
        }
        int kind = K - 2;
        if (deep == 0) kind += 1;
        deep++;
        ll res = 1;
        rep(i, cnt) {
            res *= kind;
            res %= MOD;
            kind--;
        }
        ans *= res;
        ans %= MOD;
    }

    cout << ans << endl;
    return 0; 
}