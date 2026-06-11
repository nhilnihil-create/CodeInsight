#include "bits/stdc++.h"
#include "math.h"
 
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<int> vin;
typedef pair<ll,ll> P;
typedef vector<P> vp;
#define rep(i,a,b) for(ll i=(a);i<(b);++i)
#define drep(i,a,b) for(ll i=(a);i>=(b);--i)
#define SIZE(a) int((a).size())
#define out(a) cout<<(a)<<endl;
const int INF=INT_MAX;
const int MAX = 510000;
const ll MOD = 1000000007;
ll fac[MAX], finv[MAX], inv[MAX];
ll gcd(ll a,ll b){
   if (a%b == 0){
        return(b);
    }
   else{
       return(gcd(b, a%b));
    }
}
vp factorize(ll n) {
    vp res;
    for (ll i = 2; i * i <= n; i++) {
        if (n % i != 0) continue;
        res.emplace_back(i,0);
        while (n % i == 0) {
            n /= i;
            res.back().second++;
        } 
    }
    if (n != 1) res.emplace_back(n,1);
    return res;
}
int main(){
  ll a,b;cin>>a>>b;
  ll t=gcd(a,b);
  vp ans=factorize(t);
  cout<<ans.size()+1<<endl;
}

