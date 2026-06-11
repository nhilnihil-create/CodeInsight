#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;

typedef long long int ll;
typedef pair<double, double> P;

bool cmp(P& lp, P& rp)
{
	double lt = 0, rt = 0;
	if (lp.second != 0 || lp.first != 0)
		lt = atan2(lp.second, lp.first);
	if (rp.second != 0 || rp.first != 0)
		rt = atan2(rp.second, rp.first);

	return lt < rt;
}

double dis(P& p)
{
	return sqrt(p.first * p.first + p.second * p.second);
}

int main()
{
	// 入力

	int n;
	cin >> n;
	vector<P> p(n);
	rep(i, n) cin >> p[i].first >> p[i].second;

	//

	// 処理

	sort(p.begin(), p.end(), cmp);
	double ans = 0, d = 0;
	rep(i, n)
	{
		P xy(0, 0);
		xy.first += p[i].first;
		xy.second += p[i].second;
		double d = dis(xy);
		for (int j = 1; j < n; j++)
		{
			xy.first += p[(i + j) % n].first;
			xy.second += p[(i + j) % n].second;
			d = max(d, dis(xy));
		}
		ans = max(ans, d);
	}

	//

	// 出力

	cout << setprecision(12) << fixed << ans;

	//

	return 0;
}
