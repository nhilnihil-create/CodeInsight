#include <algorithm>
#include <bitset>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stdio.h>
#include <string>
#include <vector>

#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;
using LP = pair<ll, ll>;
const double PI = 3.1415926535897932;

int main()
{
	int N;
	cin >> N;
	vector<string> Sn(N);
	rep(i, N) {
		cin >> Sn[i];
	}
	sort(Sn.begin(), Sn.end());

	vector<string> Ans;
	int max_cnt = 0;
	int lc_cnt = 0;
	rep(i, N-1) {
		if (Sn[i] == Sn[i + 1]) {
			lc_cnt += 1;
		}
		else {
			lc_cnt = 0;
		}

		if (max_cnt == lc_cnt) {
			Ans.push_back(Sn[i]);
		}
		else if (max_cnt < lc_cnt) {
			Ans.clear();
			max_cnt = lc_cnt;
			Ans.push_back(Sn[i]);
		}
	}
	if (max_cnt == 0) Ans.push_back(Sn[N-1]);

	for (auto s : Ans) {
		cout << s << endl;
	}
	return 0;
} 