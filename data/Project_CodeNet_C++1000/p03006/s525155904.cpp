#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <map>
#include <queue>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int iINF = 1001001001;
const long long llINF = 1LL << 60;
int main()
{
	// diverta 2019 Programming Contest 2-B, 1041, 
	int n; cin >> n;
	int p, q;
	vector<P> points(n);
	rep(i, n) {
		cin >> points[i].first >> points[i].second;
	}
	sort(points.begin(),points.end());

	int ans = 0;
	rep(i, n) {
		rep(j, n) {
			if (i == j) continue;
			int tmpAns = 0;
			vector<int> counted(n, false);
			p = points[j].first - points[i].first;
			q = points[j].second - points[i].second;
			if (p == 0 && q == 0) continue;
			if (p < 0) {
				p *= -1; q *= -1;
			}
			rep(k, n) {
				counted[k] = true;
				for (int l = k + 1; l < n; ++l) {
					if (counted[l] == true) continue;
					if (points[l].first - points[k].first == p &&
						points[l].second - points[k].second == q) {
						tmpAns++;
						counted[l] = true;
					}
				}
			}
			ans = max(ans, tmpAns);
		}
	}
	cout << n - ans << endl;
	return 0;
}