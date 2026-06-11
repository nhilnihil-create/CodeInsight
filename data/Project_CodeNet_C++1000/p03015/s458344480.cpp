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
ll dp0[MAX_N];
ll dp1[MAX_N];

ll modpow(ll a, ll n, ll mod){
    ll ret=1;
    while(n>0){
        if(n&1) ret=ret*a%mod;
        a=a*a%mod;
        n>>=1;
    }
    return ret;
}

int main(){
    string l;
    cin>>l;
    ll ans=0;
    ll n=l.length();
    ll a=2;
    ans+=modpow(3,n-1,MOD);
    for(ll i=1;i<n;i++){
        if(l[i]=='1'){
            ans+=a*modpow(3,n-i-1,MOD);
            a=a*2%MOD;
            ans%=MOD;
        }
        //cout<<ans<<endl;
    }
    ans+=a;
    //for(int i=0;i<n;i++) cout<<dp1[i]<<" "; cout<<endl;
    //for(int i=0;i<n;i++) cout<<dp0[i]<<" "; cout<<endl;
    ans%=MOD;
    cout<<ans<<endl;
}