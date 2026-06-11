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
    string s, t;
    cin >> s >> t;

    int n = s.length();

    vector<vector<int>> a(26);
    rep(i, n) {
        int idx = s[i] - 'a';
        a[idx].push_back(i);
    }

    ll res = 0;
    int j = -1;
    rep(i, t.length()) {
        int idx = t[i] - 'a';
        if (a[idx].size() == 0) {
            cout << -1 << endl;
            return 0;
        }

        int u = upper_bound(a[idx].begin(), a[idx].end(), j) - a[idx].begin();
        if (u == a[idx].size()) {
            j = a[idx][0];
            res += n;
        } 
        else {
            j = a[idx][u];
        }
    }

    cout << res + j + 1 << endl;

    return 0;
}