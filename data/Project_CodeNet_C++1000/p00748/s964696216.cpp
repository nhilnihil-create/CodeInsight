#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;

int MAX;
vector<int> V;
vector<int> D;
int N;
int M;
bool dp[10][1000100] = {0};

void solve(int n) {
	memset(dp, 0, sizeof(dp));

	int ans = 1;

	for (int i=0; i<N && V[i]<=n; i++)
		dp[0][V[i]] = 1;

	for (int i=1; i<6 && !dp[i-1][n]; i++) {
		ans++;
		for (int j=0; j<=n; j++) {
			if (!dp[i-1][j]) continue;
			for (int k=0; k<N && j+V[k]<=n; k++)
				dp[i][j+V[k]] = 1;
		}
	}

	cout << ans << " ";

	memset(dp, 0, sizeof(dp));

	ans = 1;

	for (int i=0; i<M && D[i]<=n; i++)
		dp[0][D[i]] = 1;

	for (int i=1; i<=MAX && !dp[1-i%2][n]; i++) {
		ans++;
		for (int j=0; j<=n; j++)
			dp[i%2][j] = 0;
		for (int j=0; j<=n; j++) {
			if (!dp[1-i%2][j]) continue;
			for (int k=0; k<M && j+D[k]<=n; k++)
				dp[i%2][j+D[k]] = 1;
		}
	}

	cout << ans << endl;
}

int main() {
	MAX = (int)pow(10.0, 6);
	for (int i=1; i*(i+1)*(i+2)/6<=MAX; i++) {
		V.push_back(i*(i+1)*(i+2)/6);
		if ( V[i-1]%2==1 ) D.push_back(i*(i+1)*(i+2)/6);
	}
	N = (int)V.size();
	M = (int)D.size();

	int n;
	cin >> n;
	while (n!=0) { 
		solve(n);
		cin >> n;
	}
	return 0;
}