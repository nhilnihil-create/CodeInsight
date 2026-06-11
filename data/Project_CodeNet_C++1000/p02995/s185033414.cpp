#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y);

ll a, b;

ll f(ll c) {
    ll res = b/c - (a-1)/c;
    return res;
}

int main() {
    ll c, d;
    cin >> a >> b >> c >> d;
    ll cd = c*d/__gcd(c,d);
    ll dis = f(c)+f(d)-f(cd);
    ll ans = b-a+1-dis;
    cout << ans << endl;
    return 0;
}