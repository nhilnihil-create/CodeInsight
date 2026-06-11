#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    ll cwari = b/c - (a-1)/c;
    //cout << cwari << endl;
    ll dwari = b/d - (a-1)/d;
    //cout << dwari << endl;
    ll koubai = c*d/__gcd(c,d);
    //cout << koubai << endl;
    ll kouwari = b/koubai - (a-1)/koubai;
    ll ans = b-a+1;
    ans -= cwari;
    ans -= dwari;
    ans += kouwari;
    cout << ans << endl;
    return 0;
}