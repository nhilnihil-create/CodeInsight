#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    ll n;
    cin >> n;
    pair<ll, ll> ans = make_pair(0,0);
    for (ll i = 1; i*i <= n; i++) {
        if (n%i == 0) {
            ans.first = i;
            ans.second = n / i;
        }
    }

    cout << ans.first + ans.second -2 << endl;
    
    return 0;
}