#include <bits/stdc++.h>
#define REP(i, m, n) for(int (i) = (m); (i) < (n); ++i)
#define rep(i, n) REP(i, 0, n)
#define all(x) (x).begin(), (x).end()
using namespace std;
using Graph = vector<vector<int>>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
typedef long long ll;
typedef pair<ll, ll> P;
const int INF = 1e9+7;
const ll LINF = 1LL<<60;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    int mx = (n - 1) * (n - 2) / 2;
    if (mx < k) {
        cout << -1 << endl;
        return 0;
    }
    vector<pair<int, int>> ans;
    // 頂点nを真ん中にするスター型のツリー
    rep(i, n - 1) {
        ans.push_back(make_pair(i + 1, n));
    }
    // 追加するedgeの候補を列挙
    int add = mx - k;
    vector<pair<int, int>> edge;
    rep(i, n - 1) {
        rep(j, i) {
            edge.push_back(make_pair(i + 1, j + 1));
        }
    }
    // ansに追加
    rep(i, add) {
        ans.push_back(edge[i]);
    }
    cout << ans.size() << endl;
    rep(i, ans.size()) {
        cout << ans[i].first << " " << ans[i].second << endl;
    }
    return 0;
}