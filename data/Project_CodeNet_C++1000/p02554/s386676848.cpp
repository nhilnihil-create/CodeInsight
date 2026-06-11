#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll MOD = 1'000'000'007;
const ld PI = acos(-1);  
const ld EPS = 0.0000000001;
const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;
#define rep(i, n) for(ll i=0; i<(ll)(n); i++)
#define repd(i, n) for(ll i=n-1; 0<=i; i--)
#define FOR(i, a, b) for(ll i=a; i<(ll)(b); i++)
#define FORD(i, a, b) for(ll i=b-1; (ll)(a)<=i; i--)
#define ALL(x) x.begin(), x.end()
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};


ll modpow(ll x, ll n, ll md=MOD){
    ll res=1, dig=x;
    while(n){
        if(n&1) res = res*dig%md;
        dig = dig*dig%md;
        n /= 2;
    }
    return res;
}


int main(){
    ll n;   cin >> n;
    ll res = modpow(10, n)+modpow(8, n)%MOD;
    res -= modpow(9, n);
    res = (res+MOD)%MOD;
    res -= modpow(9, n);
    cout << (res+MOD)%MOD << endl;
}
