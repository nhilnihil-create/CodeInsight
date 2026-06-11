#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
#define rep(i,n) for (ll i=0;i<n;++i)
#define rep2(i,a,b) for (ll i=a;i<b;++i)
const ll MOD=1000000007;
const ll INF=1e9;
const ll IINF=1e18;

template<class T> inline bool chmin(T &a,T b){
    if (a>b){
        a=b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T &a,T b){
    if (a<b){
        a=b;
        return true;
    }
    return false;
}

int main(){
    ll N,M;
    cin >> N >> M;
    vector<ll> S(N),T(M);
    rep(i,N){
        cin >> S[i];
    }
    rep(i,M){
        cin >> T[i];
    }
    vector<vector<ll>> dp(N+1,vector<ll>(M+1,0));
    vector<vector<ll>> sum(N+1,vector<ll>(M+1,0));
    dp[0][0]=sum[0][0]=1;
    rep(i,N){
        sum[i+1][0]=1;
    }
    rep(i,M){
        sum[0][i+1]=1;
    }
    rep(i,N){
        rep(j,M){
            if (S[i]==T[j]){
                dp[i+1][j+1]=sum[i][j];
            }
            sum[i+1][j+1]=sum[i][j+1]+sum[i+1][j]-sum[i][j]+dp[i+1][j+1];
            if (sum[i+1][j+1]<0){
                sum[i+1][j+1]+=MOD;
            }
            sum[i+1][j+1]%=MOD;
        }
    }
    cout << sum[N][M] << endl;
}