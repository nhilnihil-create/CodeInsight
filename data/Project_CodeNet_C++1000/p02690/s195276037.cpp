#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define REP(i,x,n) for(int i = (x); i < (n); ++i)
#define ll long long
#define P pair<ll,ll>
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()

const ll mod = 1e9+7;
const ll INF = 1e18;
const double pi = acos(-1);
//const ll mod = 998244353;

ll lcm(ll a, ll b){
    return a / __gcd(a, b) * b;
}

ll f(ll n){
    ll ret=1;
    rep(i,5) ret*=n;
    return ret;
}

int main(void)
{
    ll x;
    cin >> x;
    for(ll i=-1000; i<=1000; i++){
        for(ll j=-1000; j<=1000; j++){
            if(f(i)-f(j) == x){
                printf("%lld %lld\n",i,j);
                return 0;
            }
        }
    }
    return 0;
}
