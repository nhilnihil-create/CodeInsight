#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int gcd(int a, int b) {
    if (a%b == 0)  return b;
    else return gcd(b, a%b);
}

int main() {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    ll b_ = b/d-(a-1)/d;
    ll c_ = b/c-(a-1)/c;
    ll s = c*d/gcd(c, d);
    ll b_c = b/s-(a-1)/s;
    cout << (b-a+1)-b_-c_+b_c << endl;
    return 0;
}
