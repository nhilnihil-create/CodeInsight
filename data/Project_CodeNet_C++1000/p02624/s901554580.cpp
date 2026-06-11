#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef vector<vector<ll>> vvl;
typedef vector<ll> vl;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, cur;
    ll sum = 0;
    cin >> n;
    for(ll i = 1; i <= n; i = cur + 1) {
    	cur = n/(n/i);
    	ll up = ((n/i) * ((n/i) + 1))/2;
    	sum += ((cur - i + 1)*(i + cur))/2 * up;
    }
    cout << sum << "\n";
    return 0;
}
