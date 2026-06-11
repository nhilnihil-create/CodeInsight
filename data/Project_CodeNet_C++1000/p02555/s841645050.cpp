#include <bits/stdc++.h>
#define pi 3.14

typedef long long LL;
using namespace std;

int main()
{
	int N;
	LL dp[2001];
	LL S[2001];
	LL MOD=1e9+7;
	cin>>N;
	dp[0]=0;
	dp[1]=0;
	dp[2]=0;
	S[0]=0;
	S[1]=0;
	S[2]=0;
	for(int i=3;i<=N;i++){
		dp[i]=S[i-3]+1;
		S[i]=dp[i]+S[i-1];
		dp[i]%=MOD;
		S[i]%=MOD;
	}
	cout<<dp[N]<<endl;
	return 0;

}