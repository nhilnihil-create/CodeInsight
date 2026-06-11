#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int (i)=0; (i)<(n); (i)++)
typedef long long ll;

int main(){
	const int MOD = 1e9+7;
	int N,K;
	cin >> N >> K;
	vector<vector<ll>> C(N+1,vector<ll>(N+1,1));
	for(int i=0; i<=N; i++) for(int j=i+1; j<=N; j++) C[i][j] = 0;
	
	for(int i=1; i<=N; i++){
	  for(int j=1; j<=i; j++){
	  	C[i][j] = (C[i-1][j] + C[i-1][j-1]) % MOD;
	  }
	}

	for(int i=1; i<=K; i++){
		cout << C[N-K+1][i] * C[K-1][i-1] % MOD << endl;
	}
	
}
