#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX_N = 10002;

int N, P;
string S;

void solve()
{
	if(P==2 || P==5){
		ll ans = 0;
		for(int i=0;i<N;++i){
			int c=S[i]-'0';
			if(c%P==0) ans+=i+1;
		}
		cout << ans << '\n';
	}else{
		vector<int> d(N+1);
		int ten=1;
		for(int i=N-1;i>=0;--i){
			int c=(S[i]-'0')*ten%P;
			d[i]=(c+d[i+1])%P;
			(ten*=10)%=P;
		}
		ll ans = 0;
		vector<int> cnt(P);
		for(int i=N;i>=0;--i){
			ans+=cnt[d[i]];
			cnt[d[i]]++;
		}
		cout << ans << '\n';
	}
}

/* TLE
ll dp[2][MAX_N];

void solve()
{
	ll ans = 0;
	dp[0][0]=1;
	for(int i=0;i<N;++i){
		int pr=i%2,cur=(i+1)%2;
		memset(dp[cur],0,sizeof(dp[cur]));
		int rem = (s[i]-'0')%P;
		dp[cur][rem]+=1;
		if(!rem) ans++;
		for(int j=0;j<P;++j)if(dp[pr][j]){
			int nrem = (j*10+(s[i]-'0'))%P;
			dp[cur][nrem]+=dp[pr][j];
			if(!nrem)ans+=dp[pr][j];
		}
		for(int j=0;j<P;++j)dp[pr][j]=dp[cur][j];
	}
	cout << ans << '\n';
}
*/

int main()
{
	cin >> N >> P;
	cin >> S;
	solve();
	return 0;
}