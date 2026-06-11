/*
* @author:  codancer
* @createTime:  
*/
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll mod = 998244353;
#define pb push_back
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define fep(i,a,b) for(int i=(a);i>=(b);i--)
typedef vector<int> VI;
typedef vector<ll> VII;
typedef pair<int,int> pii;
ll dp[5000][5000];
int main(){
	int n,s;
	cin>>n>>s;
	vector<int> a(n+1);
	rep(i,1,n) cin>>a[i];
	dp[0][0]=1;
	rep(i,1,n){
		rep(j,a[i],s){
			dp[i][j]+=dp[i-1][j-a[i]];// put in S & U
			dp[i][j]%=mod;
		}
		rep(j,0,s){
			dp[i][j]+=2*dp[i-1][j];// DON'T PUT IN U
			dp[i][j]%=mod;
		}
	}
	cout<<dp[n][s]<<endl;
	return 0;
}