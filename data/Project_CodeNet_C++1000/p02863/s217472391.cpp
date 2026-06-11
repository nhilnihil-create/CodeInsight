#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;
using LLONG = long long;
const LLONG MOD = 1000000007;

// dp[i][t]:i番目までを考えたとき，時間t以内に完食できる最大満足度
int dp[3001][3001];

int main()
{
	int N, T; cin >> N >> T;
	vector<pair<int, int>> plates(N);
	for (int i = 0; i < N; ++i) cin >> plates[i].first >> plates[i].second;
	sort(plates.begin(), plates.end());
	int ans = 0;
	for (int i = 1; i <= N; ++i)
	{
		int ti = plates[i - 1].first;
		int vi = plates[i - 1].second;
		for (int t = 0; t < T; ++t)
		{
			// 通常のdp更新：t以内に完食できる場合は食べるか食べないかの最大値を選択
			// 完食できない場合は食べない
			if (t >= ti)
			{
				dp[i][t] = max(dp[i - 1][t], dp[i - 1][t - ti] + vi);
			}
			else
			{
				dp[i][t] = dp[i - 1][t];
			}
			// 完食できるできないに関わらず，１つ食べることができる
			ans = max(ans, dp[i - 1][t] + vi);
		}
	}
	cout << ans << endl;
}
