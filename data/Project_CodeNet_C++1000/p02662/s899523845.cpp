#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(int)(n); i++)

using namespace std;
using LL = long long;
using P = pair<int,int>;
const LL mod=998244353;

LL dp[3010][3010];

int main(){
	int N, S;
	cin >> N >> S;
	vector<int> A(N);
	rep(i,N) cin >> A[i];
	dp[0][0]=1;
	rep(i,N){
		rep(j,S+1){
			(dp[i+1][j]+=dp[i][j]*2)%=mod;
			if(j>=A[i]) (dp[i+1][j]+=dp[i][j-A[i]])%=mod;
		}
	}
	cout << dp[N][S] << endl;

	return 0;
}