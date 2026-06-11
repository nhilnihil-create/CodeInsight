#include <bits/stdc++.h>
#define read(n) scanf("%d",&n)
#define write(x) printf("%d",x)
#define F(i,n) for(int i = 0;i < n;i++)
#define ll long long
#define MX 100005
#define MOD 1000000007
#define INF 1000000009
#define set_dp(dp) memset(dp,-1,sizeof(dp))
using namespace std;
int n, m, dp[MX], __next[MX];
char a[MX];
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	read(n), read(m);

	scanf("%s", a);

	deque<int> q;

	set_dp(dp);
	set_dp(__next);

	if(a[n] == '0'){
		__next[n] = -1;
		dp[n] = 0;
		q.push_back(n);
	}

	for(int i = n - 1; i > -1; i--){
		while(!q.empty() && q.front() - i > m) q.pop_front();
		if(a[i] == '1') continue;
		if(!q.empty()){
			dp[i] = 1 + dp[q.front()];
			__next[i] = q.front();
			while(!q.empty() && dp[q.back()] >= dp[i]) q.pop_back();
			q.push_back(i);
		}
	}

	int j = 0;
	if(__next[j] == -1) cout<<-1;
	while(__next[j] != -1){
		cout<<__next[j] - j<<" ";
		j = __next[j];
	}

	cout<<endl;

	return 0;
}