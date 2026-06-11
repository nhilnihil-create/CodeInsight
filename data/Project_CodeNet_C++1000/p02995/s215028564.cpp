#include<bits/stdc++.h>
/* #define int long long */
/* #define double long double */
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define repa(i, s, n) for(int i = s; i < (int)n; i++)
#define MOD 1000000007
using namespace std;
using ll = long long;
typedef vector<int> vi;
typedef pair<int, int> P;
#define rrep(i,a,b) for(int i=a;i>=b;i--)

ll num(ll n, ll c, ll d){
    ll n_c = n/c;
    ll n_d = n/d;
    ll minseki = c / __gcd(c, d) * d;
    return n - n/c - n/d + n/minseki;
}

signed main(){
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    ll ans = 0;
    ll div_c = 0, div_d = 0, div_all = 0;
    ll minseki = c / __gcd(c, d) * d;
    
    
    ans = num(b, c, d) - num(a-1, c, d);
   
    cout << ans << endl;

}