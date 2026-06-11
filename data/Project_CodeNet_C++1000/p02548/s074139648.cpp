//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(x) (x).begin(), (x).end()
#define in(x, l, r) (ll)(l) <= (x) && (x) < (ll)(r)

int main() {
    int N;
    cin >> N;
    ll ans = 0;
    rep(a,1,1000000) {
        ans += (N-1) / a;
    }
    cout << ans << endl;
}