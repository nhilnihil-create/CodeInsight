//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for(int i=0;i<(n);++i)
#define all(a) (a).begin(),(a).end()
using namespace std;
using Graph = vector<vector<int>>;
typedef long long ll;
const int mod =1e+9+7;

ll RepeatSquaring(ll a, ll n, ll p){
    if(n==0) return 1;
    if(n%2==0){
        ll t = RepeatSquaring(a, n/2, p);
        return t*t % p;
    }
    return (a*RepeatSquaring(a, n-1, p))%p;
}

ll nCr(ll n, ll r, ll mod){
    ll mul = 1, div = 1;
    for(ll i = 0; i < r; i++){
        mul *= n - i;
        div *= i + 1;
        mul %= mod;
        div %= mod;
    }   
    return mul * RepeatSquaring(div, mod - 2, mod) % mod;
}
int main(){
    ll x,y; cin>>x>>y;
    if(2*x-y<0||2*y-x<0||(2*x-y)%3!=0||(2*y-x)%3!=0){
        cout<<0<<endl;
        return 0;
    }
    ll a=(2*x-y)/3,b=(2*y-x)/3;
    ll ans=nCr(a+b,a,mod);
    cout<<ans<<endl;

}







































