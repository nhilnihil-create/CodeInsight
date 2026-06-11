#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)
#define rep1(i, n) for(int i=1; i<=n; i++)
#define repr(i, n) for(int i=n-1; i>=0; i--)
#define repr1(i, n) for(int i=n; i>=1; i--)
#define all(v) v.begin(),v.end()
using ll = long long;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
const int INF = 1e9;
const ll LLINF = 1e18;
const ll MOD = 1e9+7;
const double EPS = 1e-10;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int n, a, b, c, d;
string s;

bool can_reach(int start, int goal) {
    for (int i = start; i < goal; i++) {
        if (s[i] == '#' && s[i+1] == '#') return false;
    }
    return true;
}

int main() {
    cin >> n >> a >> b >> c >> d >> s;
    a--; b--; c--; d--;

    if (!can_reach(a, c) || !can_reach(b, d)) {
        cout << "No" << endl;
        return 0;
    }

    bool ok = false;
    if (c < d) {
        ok = true;
    } else {
        for (int i = b; i <= d; i++) {
            if (s[i-1] == '.' && s[i] == '.' && s[i+1] == '.') ok = true;
        }
    }
    cout << (ok ? "Yes" : "No") << endl;
}
