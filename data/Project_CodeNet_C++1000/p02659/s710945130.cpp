#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    ll a;
    double b;
    cin >> a >> b;
    b *= 100;
    ll ib = b+0.5;
    ll ans = a*ib;
    ans /= 100;
    cout << ans << endl;
    return 0;
}