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
const int MOD = 1000000007;
const int iINF = 1001001001;
const long long llINF = 1LL << 60;
bool update(vector<int> &score, vector<vector<pair<int, int>>> xy, int person, vector<bool> &honest)
{
	rep(i, xy[person].size()) {
		if (xy[person][i].second == 0) {
			if (score[xy[person][i].first] == 1) {
				return false;
			}
			score[xy[person][i].first] = 2;
		}
		else if (xy[person][i].second == 1) {
			if (score[xy[person][i].first] == 2) {
				return false;
			}
			score[xy[person][i].first] = 1;
			if (honest[xy[person][i].first] == false) {
				honest[xy[person][i].first] = true;
				if (!update(score, xy, xy[person][i].first, honest)) return false;
			}
		}
	}
	return true;
}
int main()
{
	// ABC147-C, 975, 
	int n;
	cin >> n;
	int a;
	vector<vector<pair<int, int>>> xy(n);
	rep(i, n) {
		cin >> a;
		xy[i].resize(a);
		rep(j, a) {
			cin >> xy[i][j].first >> xy[i][j].second;
			xy[i][j].first--;
		}
	}
	int ans = 0;
	rep(i, 1 << n) {
		int tmp = 0;
		bool ok = true;
		vector<bool> honest(n, false);
		vector<int> score(n, 0);	// 0:未定義, 1:正直, 2:不親切
		rep(j, n) {
			if (i >> j & 1) {
				if (score[j] == 2) {
					ok = false;
					break;
				}
				score[j] = 1;
				if (honest[j] == false) {
					honest[j] = true;
					if (!update(score, xy, j, honest)) {
						ok = false;
						break;
					}
				}
			}
		}
		if (!ok)	continue;
		rep(j, honest.size())	tmp += honest[j];
		ans = max(ans, tmp);
	}
	cout << ans << endl;
	return 0;
}