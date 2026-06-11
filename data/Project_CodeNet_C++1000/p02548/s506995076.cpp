#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

void solve() {
    ll n;
    cin >> n;

    ll ab = 0, ans = 0;
    for (ll a = 1; a*a < n; a++) {
        ab = a;
        ans += (n-1) / a;
    }
    cout << 2*ans - ab*ab << endl;

}

int main() {
    solve();
    return 0;
}
