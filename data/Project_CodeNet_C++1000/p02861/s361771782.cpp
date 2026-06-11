#include <algorithm>
#include <bitset>
#include <cmath>
#include <iostream>
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
using P = pair<int, int>;
const double PI = 3.1415926535897932;

/* a と b の最大公約数を返す関数 */
long long GCD(long long a, long long b) {
	if (b == 0) return a;
	else return GCD(b, a % b);
}

int main()
{
	int N;
	cin >> N;
	
	vector<vector<int> > xy(N, vector<int>(2, 0));
	rep(i, N) cin >> xy[i][0] >> xy[i][1];

	vector<int> vec(N);
	vector<vector<int> > pt;
	iota(vec.begin(), vec.end(), 0);

	do {
		pt.push_back(vec);
	} while (next_permutation(vec.begin(), vec.end()));

	double total_dist = 0;
	int dist_cnt = 0;
	for (auto v : pt)
	{
		for (int i = 0; i < (N - 1); ++i)
		{
			int crt = v[i];
			int nxt = v[i + 1];
			total_dist += sqrt((xy[nxt][0] - xy[crt][0]) * (xy[nxt][0] - xy[crt][0]) +
								(xy[nxt][1] - xy[crt][1]) * (xy[nxt][1] - xy[crt][1]));
		}
		dist_cnt += 1;
	}

	printf("%.7f", total_dist / (double)dist_cnt);
	return 0;
}