#include<bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const ll MOD = (ll)1e9+7LL;
const int N = (int)1e5+99;
ll poww(ll x, ll eks) {
    if(eks==0LL) return 1LL;
    if(eks==1LL) return x;
    ll taj=poww(x, eks/2);
    return taj % MOD * taj % MOD * (eks&1?x:1LL) % MOD;
}
ll n, k, res[N], sol;
int main() {
    IOS; cin >> n >> k;
    for(ll i=k; i>0LL; --i) {
        res[i]=poww(k/i, n);
        for(ll j=2LL*i; j<=k; j+=i) {
            res[i]=(res[i]-res[j]+MOD)%MOD;
        }
        sol=(sol+res[i]*i)%MOD;
    }
    cout << sol;
    return 0;
}
