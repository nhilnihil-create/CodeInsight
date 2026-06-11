//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
 
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define ll long long
 
 
 
using namespace std;
void file(){
	#ifndef ONLINE_JUDGE
    	freopen("tst.txt", "r", stdin);
	#endif	
}
int tc;
const int N=3e5+5,M=3e5+5,MOD=1e9+7,OO=1e9;

int main()
{	
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 	//file();
 	int n,m;
 	scanf("%d %d",&n,&m);

 	std::vector<int>a(n+1),b(m+1);

 	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
 	for(int i=1;i<=m;i++)scanf("%d",&b[i]);

 	std::vector<std::vector<ll>> dp(n+1,vector<ll>(m+1,0)),sum(n+1,vector<ll>(m+1,0));
 	for(int i=1;i<=n;i++){
 		for(int j=1;j<=m;j++){
 			if(a[i]==b[j])
 				dp[i][j] = 1+sum[i-1][j-1];
 			sum[i][j] = (dp[i][j]+sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+MOD)%MOD;
 			dp[i][j]%=MOD;
 		}
 	}
 	
 	printf("%lld\n",sum[n][m]+1);
}