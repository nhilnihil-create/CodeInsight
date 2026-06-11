#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n) {
        ll o;
        cin >> o;
        o--;
        i++;
        a[o] = i;
        i--;
    }
    rep(i,n) cout << a[i] << ' ';
    return 0;
}
