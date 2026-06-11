#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define rep(i,n); for(long long i = 0;i < (n);i++)
using ll = long long;
using P = pair<long long,long long>;
template <class T> using vec = vector<T>;
template<class T>void sort(vec<T> &v){sort(v.begin(),v.end());}
template<class T>void rsort(vec<T> &v){sort(v.rbegin(),v.rend());}
const ll mod = 1e9+7;

ll powmod(ll x,ll n){
    if(n == 0)return 1;
    if(n%2)return x*powmod(x*x%mod,n/2)%mod;
    return powmod(x*x%mod,n/2)%mod;
}
ll frac[2020],ifrac[2020];
ll conbi(ll n,ll k){
    return (((frac[n]*ifrac[n-k]%mod)*ifrac[k])%mod+mod)%mod;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    rep(i,2020)i == 0 ? frac[i] = 1:frac[i] = (frac[i-1]*i%mod+mod)%mod;
    rep(i,2020)ifrac[i] = powmod(frac[i],mod-2)%mod;
    ll n,k; cin >> n >> k;
    rep(i,k){
        if(i>n-k){
            cout << 0 << endl;
            continue;
        } 
        cout << conbi(n-k+1,i+1)*conbi(k-1,i)%mod << endl;
    }
}