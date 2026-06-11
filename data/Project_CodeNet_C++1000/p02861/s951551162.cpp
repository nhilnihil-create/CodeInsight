#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <map>
#include <queue>
#include <cassert>
#include <iomanip>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define ALL(a) (a).begin(), (a).end()
#define rALL(a) (a).rbegin(), (a).rend()
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int iINF = 1001001001;
const long long llINF = 1LL << 60;
int main()
{
	// ABC145-C, 
	int n; cin >> n;
	vector<P> p(n);
	rep(i, n) cin >> p[i].first >> p[i].second;
	sort(ALL(p));
	double ans = 0;
	int num = 0;
	do {
		num++;
		double dist = 0;
		rep(i, n) {
			if (i == 0) continue;
			dist += sqrt((p[i].first - p[i - 1].first) * (p[i].first - p[i - 1].first) + (p[i].second - p[i - 1].second) * (p[i].second - p[i - 1].second));
		}
		ans += dist;
	} while (next_permutation(p.begin(), p.end()));
	cout << setprecision(15) << ans / num << endl;

	return 0;
}