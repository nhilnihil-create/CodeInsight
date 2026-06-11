#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0;i<ll(n);i++)

int main() {
    ll n , k;
    cin >> n >> k;
    cout << min(n - k*(ll)(n/k), k*(ll)(n/k) + k - n) << endl;
    return 0;
}
