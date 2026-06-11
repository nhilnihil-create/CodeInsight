#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>
#include <queue>
#include <iomanip>

template<typename T> bool chmax(T &a,T b){
    if(a<b){
        a=b;
        return true;
    }
    return false;
}

template<typename T> bool chmin(T &a,T b){
    if(a>b){
        a=b;
        return true;
    }
    return false;
}

using namespace std;
using ll = long long int;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vvll> vvvll;
const int MOD=1000000007;
//const int MOD=998244353;
const int INTMAX=1001001000;
const ll LLMAX=1010010010010010000;

ll modadd(ll a,ll b,ll mod=MOD){
    return (a%mod+b%mod)%mod;
}

ll modsub(ll a,ll b,ll mod=MOD){
    a%=mod;
    b%=mod;
    if(a>=b) return a-b;
    else return mod-b+a;
}

ll modmul(ll a,ll b,ll mod=MOD){
    return ((a%mod)*(b%mod))%mod;
}

ll modpow(ll a, ll n,ll mod=MOD) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

ll moddiv(ll a,ll b,ll mod=MOD) {
    return modmul(a, modpow(b, mod-2));
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    string L;
    cin>>L;
    ll N=L.size();
    
    vvll dp(N,vll(2));//j=0:a+bがL未満確定
    for(int i=0;i<N;i++){
        int X=L[i]-'0';
        if(i==0){
            //X==1
            dp[i][0]=1;//0,0
            dp[i][1]=2;//1,0
        }else{
            if(X==1){
                dp[i][0]=modadd(modmul(dp[i-1][0],3),dp[i-1][1]);
                dp[i][1]=modmul(dp[i-1][1],2);
            }else{
                dp[i][0]=modmul(dp[i-1][0],3);
                dp[i][1]=dp[i-1][1];
            }
        }
    }
    cout<<modadd(dp[N-1][0],dp[N-1][1])<<endl;
    
    return 0;
}
