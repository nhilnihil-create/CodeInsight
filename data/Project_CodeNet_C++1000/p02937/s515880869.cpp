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
    string s,t;
    cin >> s >> t;
    vector<vector<int>> v(26);
    for (int i = 0; i < s.size(); ++i) {
        v[s[i] - 'a'].push_back(i);
    }

    ll res = 0;
    int now = -1;
    for (int i = 0; i < t.size(); ++i) {
        int c = t[i] - 'a';
        if (v[c].empty()) {
            cout << -1 << endl;
            return 0;
        }

        auto itr = upper_bound(all(v[c]), now);
        if (itr == v[c].end()) {
            res += (ll)s.size() - now + v[c][0];
            now = v[c][0];
        } else {
            res += *itr - now;
            now = *itr;
        }
    }
    cout << res << endl;
}