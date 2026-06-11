#include <bits/stdc++.h>
#define rep(i, a) for (ll i = 0; i < (a); ++i)
#define pb push_back
#define all(v) v.begin(),v.end()
#define sort_1(v) sort(v.begin(),v.end())
#define sort_2(v) sort(v.begin(),v.end(),greater<ll>())
#define reverse(v) reverse(v.begin(),v.end())
typedef long long ll;
typedef long double la;
using namespace std;

int main(){
    ll s;
    cin >> s;
    ll l = pow(10,9);
    ll x1 = 0;
    ll y1 = 0;
    ll x2 = l;
    ll y2 = 1;
    ll x3 = (l - s%l)%l;
    ll y3 = (s+x3)/l;
    cout << x1 << " " << y1 << " " << x2 << " " << y2 << " " << x3 << " " << y3 << endl;
}