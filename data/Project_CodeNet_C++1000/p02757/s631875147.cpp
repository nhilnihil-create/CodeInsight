#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) x.begin(),x.end()

int const N = 200001;
ll r[N], f[N]; 

int main(){
    ll n, k; 
    string s; 
    cin >> n >> k >> s;
    if(k == 2 || k == 5){
        ll an = 0;
        for(int i = 0; i<n; ++i){
            if((s[i]-'0') % k == 0){
                an = (ll)(an + (i+1));
            }
        }
        return printf("%lld\n", an),0;
    }
    reverse(all(s));
    ll cur = 0, t = 1; 
    for(int i = 0; i<n; ++i){
        r[i] = (1ll * t * (s[i]-'0'))%k;
        t = (1ll * t * 10)%k;
    }
    ll an = 0;
    t = 0;
    for(int i = 0; i<n; ++i){
        t = (t%k + r[i]%k) % k;
        ++f[t];
    }
    for(int i = 0; i<k; ++i){
        an = (ll) (an + (1ll * f[i] * (f[i]-1))/2ll);
    }
    an = (ll) (an + f[0]);
    printf("%lld\n", an);
}