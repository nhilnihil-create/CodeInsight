#include<bits/stdc++.h>
//g++ -std=c++11 

using namespace std;
typedef long long ll;

#define rep(i,n) for (long long i = 0; i < (n); ++i)
#define DIV 1000000007 //10^9+7

ll N, M;
ll S[2005];
ll T[2005];
ll memo[2005][2005];

int main(){
	cin >> N >> M;
	rep(i, N)  cin >> S[i + 1];
	rep(i, M) cin >> T[i + 1];


	rep(i, N + 1) memo[i][0] = 1;
	rep(j, M + 1) memo[0][j] = 1;

	// S
	for(ll i = 1; i <= N; i++) {
		// T
		for(ll j = 1; j <= M; j++) {
			if(S[i] == T[j]) {
				memo[i][j] = memo[i-1][j] + memo[i][j-1];
				memo[i][j] += DIV;
				memo[i][j] %= DIV;
			} else {
				memo[i][j] = memo[i-1][j] + memo[i][j-1] - memo[i-1][j-1];
				memo[i][j] += DIV;
				memo[i][j] %= DIV;
			}	
		}
	}

	cout << memo[N][M] << endl;
}
