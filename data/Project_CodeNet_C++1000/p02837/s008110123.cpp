#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF = (1<<30) - 1;
const ll LINF = (1LL<<60) - 1;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    vector<vector<pii>> t(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        int x, y;
        for (int j = 0; j < a[i]; ++j) {
            cin >> x >> y;
            x--;
            t[i].push_back(pii(x, y));
        }
    }

    int res = 0;
    for (int i = 0; i < (1<<n); ++i) {
        vector<bool> v(n, false);
        for (int j = 0; j < n; ++j) {
            if (i & (1<<j)) v[j] = true;
        }

        for (int j = 0; j < n; ++j) {
            if (!v[j]) continue;

            for (auto &p : t[j]) {
                if (p.second == 1 && !v[p.first]) goto next;
                if (p.second == 0 && v[p.first]) goto next;
            }
        }
        chmax(res, __builtin_popcount(i));
        next:;
    }
    cout << res << endl;
}