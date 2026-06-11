#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pair2;
typedef pair<int, pair<int, int> > pair3;
typedef pair<int, pair<int, pair<int, int> > > pair4;
#define MAXN 313
#define INF 1000000000000000000LL
#define MOD 1000000007LL
#define IINF 1000000000
#define mp make_pair
#define pb push_back
#define remove pop
#define all(x) x.begin(), x.end()


int n, k;
ll h[MAXN];


ll dp[MAXN][MAXN][MAXN];

int main() {
	if (fopen("FILENAME.in", "r")) {
		freopen("FILENAME.in", "r", stdin);
		freopen("FILENAME.out", "w", stdout);
	}
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);


	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> h[i];
	}

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= k; j++) {
			for (int l = 0; l <= n; l++) {
				dp[i][j][l] = INF;
			}
		}
	}

	dp[0][0][0] = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= k; j++) {
			for (int l = 0; l <= i; l++) {
				if (dp[i][j][l] == INF) continue;

				//cout << "at " << i << ' ' << j << ' ' << l << " have " << dp[i][j][l] << endl;
				dp[i + 1][j + 1][l] = min(dp[i + 1][j + 1][l], dp[i][j][l]); //Skipped

				dp[i + 1][j][i + 1] = min(dp[i + 1][j][i + 1], dp[i][j][l] + max(0LL, h[i] - (l == 0 ? 0 : h[l - 1])));
			}
		}
	}

	ll answer = INF;

	for (int i = 0; i <= k; i++) {
		for (int l = 0; l <= n; l++) {
			answer = min(answer, dp[n][i][l]);
		}
	}

	cout << answer << endl;

}

//GCD GCD GCD USE GCD IN MATH