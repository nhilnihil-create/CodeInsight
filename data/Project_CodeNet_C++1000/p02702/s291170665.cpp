#include <bits/stdc++.h>
#define MOD 1000000007LL
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

string s;
ll dp[2][2020];

int main(void){
	cin >> s;
	int n=s.size();
	int cur=0,nxt=1;
	ll ans=0;
	for(int i=0;i<n;i++){
		ans+=dp[cur][0];
		for(int j=0;j<2020;j++){
			int nj=(j*10+(s[i]-'0'))%2019;
			dp[nxt][nj]+=dp[cur][j];
		}
		dp[nxt][(s[i]-'0')]++;
		swap(cur,nxt);
		for(int j=0;j<2020;j++){
			dp[nxt][j]=0;
		}
	}
	ans+=dp[cur][0];
	printf("%lld\n",ans);
	return 0;
}
