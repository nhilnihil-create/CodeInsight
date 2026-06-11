#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
const int INF = 1001001001;
const int mod = 1000000007;

// ll gcd(ll a,ll b){return b ? gcd(b,a%b) : a;}
// ll lcm(ll a,ll b){return a / gcd(a,b) * b;}
ll gcd(ll a,ll b){return b ? gcd(b,a%b) : a;}
ll lcm(ll a,ll b){return a / gcd(a,b) * b;}
int main(){
    ll a,b,c,d;
    cin >> a >> b >> c >> d;
    ll nc = b / c - (a-1) / c;
    ll nd = b / d - (a-1) / d;
    ll ncd = b / lcm(d,c) - (a-1) / lcm(d,c);
    ll ans = max((b-a+1)-(nc + nd - ncd),ll(0));
    cout << ans << endl;
}