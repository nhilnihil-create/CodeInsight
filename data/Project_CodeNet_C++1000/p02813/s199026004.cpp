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
	vector<int> P(N, 0);
	vector<int> Q(N, 0);
	rep(i, N) {
		cin >> P[i];
	}
	rep(i, N) {
		cin >> Q[i];
	}

	vector<int> base;
	rep (i, N) {
		base.push_back(i + 1);
	}

	int pp = -1;
	int pq = -1;
	int cnt = 1;
	do {
		bool fpp = true;
		bool fpq = true;
		for (int i = 0; i < N; ++i) {
			if (P[i] != base[i]) fpp = false;
			if (Q[i] != base[i]) fpq = false;
		}

		if (fpp) pp = cnt;
		if (fpq) pq = cnt;
		cnt += 1;

	} while (std::next_permutation(base.begin(), base.end()));

	cout << abs(pq - pp) << endl;
	return 0;
} 
