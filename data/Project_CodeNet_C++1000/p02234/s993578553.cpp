#include <iostream>
using namespace std;
#define MAX_SIZE (101)

int main() {
	int n;
	cin >> n;
	// p[i-1], p[i] correspond to M[i]'s row and column size
	int p[MAX_SIZE];
	for (int i=1;i<=n;++i) {
		cin >> p[i-1] >> p[i];
	}
	// [i][j] is a cost for multiplying matrices between M[i] and M[j].
	int dp[MAX_SIZE][MAX_SIZE];
	// [i][i] = 0, i=1,...,n
	for (int i=1;i<=n;++i) {
		dp[i][i] = 0;
	}
	// [i][j], i<j, i=1,...,n
	// j - i = l-1 = 1,2,...,n-1
	// このindexの指定の仕方: なんとなくnまでに合わせたい, l=2,...,nで(l-1)=1,...,n-1になる
	// j = i + (l-1)で, i+1, ..., n まで動く.
	for (int l=2;l<=n;++l) {
		for (int i=1;i<=n-l+1;++i) {
			int j = i + l - 1;// i+1, i+2, ..., n
			dp[i][j] = (1 << 30); 
			for (int k=i;k<j;++k) {
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + p[i-1] * p[k] * p[j]); 
			}
		}
	}
	cout << dp[1][n] << endl;
	return 0;
}


