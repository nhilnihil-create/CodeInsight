#include <iostream>
#include <vector>
using namespace std;
int INF = 10000000;
int main(){
	int N, M;
	cin >> N >> M;
	vector<int> a(M), S(M, 0);
	for (int i = 0; i < M; i++){
		cin >> a[i];
		int b;
		cin >> b;
		for (int j = 0; j < b; j++){
			int c;
			cin >> c;
			S[i] += 1 << (c - 1);
		}
	}
	int K = 1 << N;
	vector<int> dp(K, INF);
	dp[0] = 0;
	for (int i = 1; i < K; i++){
		for (int j = 0; j < M; j++){
			dp[i] = min(dp[i], dp[i & ~S[j]] + a[j]);
		}
	}
	if (dp[K - 1] == INF){
		cout << -1 << endl;
	} else {
		cout << dp[K - 1] << endl;
	}
}