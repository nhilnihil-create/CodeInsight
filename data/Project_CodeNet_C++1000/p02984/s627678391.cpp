#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0;i<ll(n);i++)

int main() {
    ll ans, n;
    ans = 0;
    cin >> n;
    vector<int> a(n), b(n, 0);
    ll sumA = 0;
    int sign = 1;
    rep(i, n) {
        cin >> a[i];
        sumA += a[i]*sign;
        sign *= -1;
    }
    ll y = sumA/2;
    rep(i, n - 1){
        cout << 2*y << ' ';
        y = a[i] - y;
    }
    cout << 2*y << endl;
    return 0;
}

