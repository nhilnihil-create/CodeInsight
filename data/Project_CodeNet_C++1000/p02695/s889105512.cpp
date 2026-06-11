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
using P = pair<ll, ll>;
const int iINF = 1001001001;
const long long llINF = 1LL << 60;

int n, m, q;
int dmax = 0;
vector<vector<int>> param;

void rec(vector<int> a)
{
	if (a.size() == 0) {
		for(int i = 1; i <= m; ++i) {
			vector<int> next = a;
			next.push_back(i);
			rec(next);
		}
	}
	else if (a.size() == n) {
		int d = 0;
		rep(i, q) {
			if (a[param[i][1]] - a[param[i][0]] == param[i][2]) d += param[i][3];
		}
		dmax = max(dmax, d);
		return;
	}
	else {
		for (int i = a.back(); i <= m; ++i) {
			vector<int> next = a;
			next.push_back(i);
			rec(next);
		}
	}
}
int main()
{
	// ABC165-C, 1197, 
	cin >> n >> m >> q;
	param.resize(q);
	rep(i, q) {
		param[i].resize(4);
		rep(j, 4) cin >> param[i][j];
		param[i][0]--; param[i][1]--;
	}
	vector<int> a;
	rec(a);
	cout << dmax << endl;

	return 0;
}