#include "bits/stdc++.h"
using namespace std;

typedef long long ll;

const int MOD = 1000000007;
const int INF = 1001001001;
const double PI = acos(-1);

#define rep(i, n)  for(int i=0;i<(n);++i)
#define all(x) (x).begin(),(x).end()

int main() {
    string s;
    cin >> s;
    vector<ll> a(s.size()+1, 0), b(s.size()+1, 0);

    rep(i, s.size()) {
        if (s[i] == '<') {
            a[i+1] = a[i] + 1;
        }
    }

    for(int i = s.size() - 1; i >= 0; i--) {
        if (s[i] == '>') {
            b[i] = b[i+1] + 1;
        }
    }

    ll ans = 0;
    rep(i, s.size() + 1) {
        ans += max(a[i], b[i]);
    }

    cout << ans << endl;
}
