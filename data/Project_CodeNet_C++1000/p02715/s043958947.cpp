#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
#include<queue>
#include<map>
#include<deque>
#include<bitset>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
typedef pair<int,int> P;
template<class T> inline bool chmax(T&ans , T b){ if(ans<b){ ans=b; return true; } else{ return false; } }
template<class T> inline bool chmin(T&ans , T b){ if(ans>b){ ans=b; return true; } else{ return false; } } 

const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

ll poww(ll x,ll n){
    ll ret = 1;
    while(n>0){
        if(n&1) ret = ret * x % MOD;
        x = x*x % MOD;
        n >>= 1;
    }
    return ret;
}

int main(){
    int n,k;
    cin >> n >> k;
    ll d[k+1];
    for(int i=k;i>=1;i--){
        int cnt = k/i;
        d[i] = poww(cnt,n);
        d[i] %= MOD;
    }
    for(int i=k;i>=1;i--){
        for(int j=2*i;j<=k;j+=i){
            d[i] -= d[j];
            d[i] %= MOD;
        }
    }

    ll ans=0;
    for(int i=1;i<=k;i++){
        ans += d[i]*i%MOD;
        ans %= MOD;
    }
    cout << ans << endl;
}