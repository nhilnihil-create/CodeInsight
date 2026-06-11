#include<bits/stdc++.h>

#define _GLIBCXX_DEBUG
#define all(v) (v).begin(),(v).end()

using namespace std;

using ll=long long;
using pii=pair<int, int>;
using vi=vector<int>;

const ll LINF=1LL<<60;
const int INF=1<<29;
const ll MOD=998244353;


ll modpow(ll a, ll n){
    ll res=1;
    while(n > 0){
        if(n & 1) res=res*a%MOD;
        a=a*a%MOD;
        n>>=1;
    }
    return res;
}


int main(){
    int N, S; cin >> N >> S;
    vi A(N);
    for(auto &x : A){
        cin >> x;
    }
    vector<vector<ll>> dp(N+1, vector<ll>(S+1, 0));
    dp[0][0]=modpow(2, N);
    ll x=modpow(2LL, MOD-2);
    for(int i=0; i<N; i++){
        for(int j=0; j<=S; j++){
            if(j >= A[i]){
                dp[i+1][j]=(dp[i][j-A[i]]*x%MOD+dp[i][j]%MOD)%MOD;
            }
            else dp[i+1][j]=dp[i][j]%MOD;
        }
    }
    cout << dp[N][S] << endl;
    return 0;
}