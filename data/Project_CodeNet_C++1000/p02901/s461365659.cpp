#include<iostream>
#include<algorithm>
#include<functional>
#include<cmath>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<deque>
using namespace std;
#define ll long long
const int mod = 1000000007;
const ll INF = 1000000000000000000;

int a[1010], b[1010];
int c[1010][15];
ll dp[1010][(1 << 12)];
int main()
{
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> a[i] >> b[i];
		for (int j = 0; j < b[i]; j++) {
			int C;
			cin >> C;
			C--;
			c[i][C] = 1;
		}
	}
	for (int i = 0; i <= M; i++) {
		for (int j = 0; j < (1 << N); j++) {
			dp[i][j] = INF;
		}
	}
	dp[0][0] = 0;
	for (int i = 0; i < M; i++) {
		for (int bit = 0; bit < (1 << N); bit++) {
			dp[i + 1][bit] = min(dp[i + 1][bit], dp[i][bit]);
			int num = 0;
			int tmp = bit;
			ll power = 1;
			for (int j = 0; j < N; j++) {
				if (c[i][j] == 1 || tmp % 2 == 1) {
					num += power;
				}
				tmp /= 2;
				power *= 2;
			}
			//cout << num << endl;
			dp[i + 1][num] = min(dp[i + 1][num], dp[i][bit] + a[i]);
		}
	}
	if (dp[M][(1 << N) - 1] != INF) cout << dp[M][(1 << N) - 1] << endl;
	else cout << -1 << endl;
}