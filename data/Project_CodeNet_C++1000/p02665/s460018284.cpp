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

int main()
{
    int N; cin >> N;
    if (N == 0)
    {
        // 根ノードのみの場合
        int a0; cin >> a0;
        cout << (a0 == 1 ? 1 : -1) << endl;
        return 0;
    }
    vector<LLONG> as(N + 1); for (auto &ai : as) cin >> ai;
    if (as[0] != 0)
    {
        // 深さN>0のとき，A0はゼロでなければならない
        cout << -1 << endl;
        return 0;
    }
	vector<LLONG> sums(N + 1);	// sums[i] = Ai + ... + AN
	LLONG sum = 0;
	for (int i = N; i >= 0; --i)
	{
		sums[i] = sum;
		sum += as[i];
	}
	// 各深さdにおいて葉でない頂点数bs[d]を計算する
	vector<LLONG> bs(N + 1);
	bs[0] = 1;
	for (int d = 1; d <= N; ++d)
	{
		bs[d] = min(sums[d], bs[d - 1] * 2 - as[d]);
	}
	LLONG ans = 0;
	for (int d = 0; d <= N; ++d)
	{
		if (bs[d] < 0)
		{
			ans = -1;
			break;
		}
		ans += as[d] + bs[d];
	}
	cout << ans << endl;
}