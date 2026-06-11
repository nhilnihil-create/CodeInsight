//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define INF 100000000
#define rep(i,s,n) for (int i = (int)(s); i < (int)(n); i++)
#define repp(i,n,s) for (int i= (int)(n); i >= (int)(s); i--)
#define mp make_pair
ll mod = 1000000007;
ll mod2 = 998244353;

ll calc(ll n,int a){
    ll num = 1;
    rep(i,0,n){
        num = num*a%mod;
    }
    return num%mod;
}

int main(){
	cin.tie(0);
    ios::sync_with_stdio(false);
    ll n;cin>>n;
    ll ans = 0;
    ll num = 1;
    ans = (ans+calc(n,10))%mod;
    ans = (ans-calc(n,9)+mod)%mod;
    ans = (ans-calc(n,9)+mod)%mod;
    ans = (ans+calc(n,8))%mod;
    cout<<ans<<endl;
}