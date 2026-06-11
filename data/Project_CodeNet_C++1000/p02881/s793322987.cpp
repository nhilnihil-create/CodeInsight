#include <bits/stdc++.h>
using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define ALL(x) x.begin(),x.end()
const ll LINF = 1e18;
using namespace std;



int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    ll n;
    cin >> n;
    ll sum = LINF;
    for (ll i = 1; i*i <= n; ++i) {
        if (n % i == 0) {
            sum = min(sum, (i -1) + (n/i -1));
        }
    }
    cout << sum << endl;
    return 0;
}