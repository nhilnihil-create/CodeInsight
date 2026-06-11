#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(ll i=0;i<n;i++)
#define P pair<ll,ll>
#define Graph vector<vector<ll>>
#define INF (1ll<<60)
#define mod 998244353
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return true;} return false;}
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return true;} return false;}

ll modpow(ll x,ll n) {
    ll ret=1;
    while(n>0){
        if(n&1) ret=ret*x%mod;  // n の最下位bitが 1 ならば x^(2^i) をかける
        x=x*x%mod;
        n>>=1;  // n を1bit 左にずらす
    }
    return ret;
}

int main(){
	ll n,s;cin>>n>>s;
	vector<ll> a(n);
	rep(i,n) cin>>a[i];

	vector<vector<ll>> dp(3010,vector<ll>(3010,0));//i個選べるとき　和がjになるような組み合わせの個数
	
	dp[0][0]=1;

	rep(i,n){//i番目まで選べるとき
		rep(j,s+1){//和がjちょうどになるとき	
			if(j+a[i]<=s){
				dp[i+1][j+a[i]]+=dp[i][j];//i番目を選ぶとき
				dp[i+1][j+a[i]]%=mod;
			}
			dp[i+1][j]+=2*dp[i][j];//i番目を選ばないとき(選択肢が1つ減ると、場合の数は2倍)
			dp[i+1][j]%=mod;
		}
	}

	cout<<dp[n][s]<<endl;

	return 0;
}