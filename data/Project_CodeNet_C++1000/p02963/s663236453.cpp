#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
const ll MAX = 1001001;
const ll MOD = 1000000007;
int main()
{
    ll s;
    cin >> s;
    ll a, b, c, d;
    if (s<1000000000) {
        a=s;
        d=1;
        b=0;
        c=0;
    }
    else {
        a=1000000000;
        d=(s-1)/a+1;
        b=a*d-s;
        c=1;
    }
    cout<<0<<" "<<0<<" "<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
}