#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define FOR(i, m, n) for (int i = (m); i < (n); i++)
#define REP(i, n) FOR(i, 0, n)
#define REP1(i, n) FOR(i, 1, (n) + 1)
#define ALL(c) (c).begin(), (c).end()
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return true;} return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return true;} return false;}
const int MOD = 1000000007;

int main() {
    int n;
    string s;
    cin >> n >> s;

    if (s[0] == 'W' || s[n * 2 - 1] == 'W') {
        cout << 0 << endl;
        return 0;
    }

    vector<int> v(n * 2, 1);

    REP1(i, n * 2 - 1) {
        if (s[i] == s[i - 1]) {
            if (v[i - 1] == 1) {
                v[i] = -1;
            } 
        } else {
            if (v[i - 1] == -1) {
                v[i] = -1;
            }
        }
    }

    ll t = 1;
    ll c = 1;
    REP1(i, n * 2 - 2) {
        if (v[i] == -1) t = (t * c) % MOD;
        c += v[i];
        if (c < 0) {
            cout << 0 << endl;
            return 0;
        }
    }
    c += v[n * 2 - 1];
    if (c != 0) {
        cout << 0 << endl;
        return 0;
    }

    REP1(i, n) {
        t = t * i % MOD;
    }
    cout << t << endl;
}