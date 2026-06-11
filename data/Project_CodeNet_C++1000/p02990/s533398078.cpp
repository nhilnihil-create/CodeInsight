#include <iostream>
#include <complex>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <stack>
#include <deque>
#include <random>
#include <iomanip>
typedef long long int ll;
typedef long double ld;
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
const ll MOD=1000000007;
const ll MAX_N=500010;
const ll INF=999999999999;
ll fac[2010];

ll modpow(ll a, ll b){
    ll res=1;
    while(b>0){
        if(b&1) res=res*a%MOD;
        a=a*a%MOD;
        b=b>>1;
    }
    return res;
}

ll comb(ll n, ll r){
    ll res=1;
    res*=fac[n];
    res*=modpow(fac[r],MOD-2);
    res%=MOD;
    res*=modpow(fac[n-r],MOD-2);
    res%=MOD;
    return res;
}
int main(){
    ll n,k;
    cin>>n>>k;
    fac[0]=1;
    for(ll i=1;i<2010;i++){
        fac[i]=fac[i-1]*i%MOD;
    }
    for(ll i=1;i<=k;i++){
        ll ans=0;
        for(ll j=0;j<=n-k-i+1;j++){
            ans+=comb(k-1,i-1)*comb(j+i-1,j)%MOD;
            ans%=MOD;
        }
        cout<<ans<<endl;
    }
    return 0;
}