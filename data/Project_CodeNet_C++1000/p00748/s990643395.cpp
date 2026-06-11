#include "bits/stdc++.h"
#define int long long
#define REP(i, s, n) for (signed i = (s); i < signed(n); i++)
#define rep(i, n) REP(i, 0, n)
#define all(c) (c).begin(), (c).end()


const int INF = 1 << 29;

using namespace std;

using VV = vector<vector<int>>;
using V = vector<int>;
using P = pair<int, int>;
using IP = pair<int, P>;

int dr[] = { -1, 0, 1, 0 };
int dc[] = { 0, -1, 0, 1 };
const int MOD = 1000000007;

signed main() {

	const int Maxnum = 1000000;
	vector<int> seisi = { 1 };
	int num = 2;
	while (seisi.back() <= Maxnum)
	{
		seisi.push_back(num * (num + 1) * (num + 2) / 6);
		num++;
	}

	vector<int> dp(Maxnum + 1, INF), kidp(Maxnum + 1, INF);
	dp[0] = 0;
	kidp[0] = 0;
	rep(i, Maxnum) {

		rep(j, seisi.size()) {
			if (i + seisi[j] > Maxnum) break;
			dp[i + seisi[j]] = min(dp[i + seisi[j]], dp[i] + 1);

			if (seisi[j] % 2) {
				kidp[i + seisi[j]] = min(kidp[i + seisi[j]], kidp[i] + 1);
			}
		}
	}

	int n;
	while (cin >> n && n) {

		cout << dp[n] << " " << kidp[n] << endl;
	}

}