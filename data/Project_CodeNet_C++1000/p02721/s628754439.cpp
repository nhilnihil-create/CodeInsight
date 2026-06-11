#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX_N = 2e5+2;
int N, K, C;
string S;
int dp1[MAX_N], dp2[MAX_N];

void solve()
{
	for(int i=1;i<=N;++i){
		if(S[i-1] == 'x') dp1[i]=dp1[i-1];
		else{
			dp1[i]=dp1[i-1];
			if(i<=C) dp1[i]=max(dp1[i], 1);
			else dp1[i]=max(dp1[i], 1+dp1[i-C-1]);
		}
	}
	for(int i=N;i>=1;--i){
		if(S[i-1]=='x') dp2[i]=dp2[i+1];
		else{
			dp2[i]=dp2[i+1];
			if(i+C>N) dp2[i]=max(dp2[i],1);
			else dp2[i]=max(dp2[i],1+dp2[i+1+C]); 
		}
	}
	for(int i=1;i<=N;++i)if(S[i-1]!='x'){
		if(dp1[i-1]+dp2[i+1] < K) cout << i << '\n';
	}
}

int main()
{
	cin >> N >> K >> C;
	cin >> S;
	solve();
	return 0;
}