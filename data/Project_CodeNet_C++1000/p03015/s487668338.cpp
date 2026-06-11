#include<bits/stdc++.h>
using namespace std; 
typedef long long ll;
typedef long double ld;
#define pb push_back
#define fi first
#define se second
const ll mod = 1e9+7;
const int N = 2e5+6;
string s; 
ll dp[N][2];
int n;
ll go(int idx,int c){
	if(idx==n){
		return 1;
	}
	ll ret = dp[idx][c];
	if(ret!=-1)return ret;
	ret = 0;
	if(s[idx]=='0'){
		ret+=go(idx+1,c);
		ret%=mod;
		if(c==1){
			ret+=2ll*go(idx+1,1);
			ret%=mod;
		}
	}
	else{
		ret+=go(idx+1,1);
		ret%=mod;
		ret+=2ll*go(idx+1,c);
		ret%=mod;
	}
	return dp[idx][c] = ret;
}
void solve(){
	memset(dp,-1,sizeof dp);
	cin>>s;
	n = s.size(); 
	cout<<go(0,0)<<endl;
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t=1; 
//	cin>>t; 
	while(t--){
		solve();
	}
	return 0;
}
