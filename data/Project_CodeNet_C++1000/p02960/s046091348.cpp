#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)

typedef long long ll;

int main(){
	const int MOD = 1e9+7;
	const int N = 13;
	string S;
	cin >> S;
	vector<uint> dp(N);
	dp[0] = 1;

	int mul = 1;
	for(int i=S.size()-1; i>=0; i--){
		vector<uint> nextDP(N);

		char c = S[i];
		if(c=='?'){
			for(int k=0; k<10; k++){
				for(int j=0; j<N; j++){
					nextDP[(k*mul+j)%N] += dp[j];
					nextDP[(k*mul+j)%N] %= MOD;
				}
			}
		}else{
			int k=S[i]-'0';
			for(int j=0; j<N; j++){
				nextDP[(k*mul+j)%N] += dp[j];
				nextDP[(k*mul+j)%N] %= MOD;
			}
		}
		dp = nextDP;
		mul *= 10;
		mul %= N;
	}

	cout << dp[5] << endl;

}

