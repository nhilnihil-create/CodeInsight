#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    ll n, a, b;
    cin >> n >> a >> b;
    ll amari = n % (a + b);
    ll ans;
    ans = ((n - amari) / (a + b)) * a;
    if(amari <= a) {
        ans += amari;
    } else {
        ans += a;
    }
    cout << ans << endl;
    return 0;
}