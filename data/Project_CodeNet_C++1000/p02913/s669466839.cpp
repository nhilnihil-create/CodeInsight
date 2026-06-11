#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
#define ALL(v)   (v).begin(),(v).end()
#define debug(x) cerr<<#x<<": "<<(x)<<endl
using namespace std;
using llong = long long;
using vi    = vector<int>;
using vvi   = vector<vi >;
using vvvi  = vector<vvi >;
using pii   = pair<int,int>;
constexpr int    INF=1e9;
constexpr double EPS=1e-9;
constexpr int    MOD=1e9+7;
template<class Type>
void line(const Type &a){int cnt=0;for(const auto &elem:a){cerr<<(cnt++?' ':'>');cerr<<elem;}cerr<<endl;}

int main(){//Refering other editorials.
	int n;
	string s;
	cin>>n>>s;
	
	vvi dp(n+1,vi(n+1,0));//dp[l][r]:=(l番目とr番目から始まる部分文字列の共通の長さ).
	for(int l=n-1;l>=0;--l)for(int r=n-1;r>l;--r){
		if(s[l]==s[r]) dp[l][r]=dp[l+1][r+1]+1;
	}
	
	int ans=0;
	REP(l,n-1)for(int r=l+1;r<n;++r){
		ans=max(ans,min(dp[l][r],r-l));
	}
	
	cout<<ans<<endl;
	return 0;
}