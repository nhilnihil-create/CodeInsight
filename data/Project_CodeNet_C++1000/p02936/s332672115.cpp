#include <bits/stdc++.h>
using namespace std;
#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
typedef long long ll;
const long long INF = 1LL << 60;
const int MAX_V = 200001;
typedef pair<int, int> P;

vector<vector<int>> G(MAX_V);
vector<ll> ans(MAX_V);

void dfs(int v, int p, ll cost) {
    ans[v] += cost;
    for (int to : G[v]) {
        if (to == p) continue;
        dfs(to, v, ans[v]);
    }
}

int main()
{
    int N, Q;
    cin >> N >> Q;

    rep(i, N - 1) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    rep(i, Q) {
        int p, x;
        cin >> p >> x;
        p--;
        ans[p] += x;
    }

    dfs(0, -1, 0);

    rep(i, N) {
        cout << ans[i] << endl;
    }
    return 0;
}