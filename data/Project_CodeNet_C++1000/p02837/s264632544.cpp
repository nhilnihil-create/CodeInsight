#include <bits/stdc++.h>

using namespace std;
long long mypow(long long x, long long y)
{
	long long result = 1;
	while (y != 0) {
		if (y%2 != 0) {
			result *= x;
			y -= 1;
		}	
		x *= x;
		y /= 2;
	}
	return result;
}

int main(void)
{
	int n;
	cin >> n;
	vector<vector<pair<int, int>>> G;
	G.resize(n);
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		for (int j = 0; j < a; j++) {
			int x, y;
			cin >> x >> y;
			G[i].push_back(make_pair(x-1, y));
		}
	}
	
	int max_ans = 0;
	for (uint32_t i = 0; i < mypow(2, n); i++) {
		bool trusted[n];
		int count = 0;
		for (int j = 0; j < n; j++) {
			if (((i >> j)&1) == 1) {
				trusted[j] = true;
				count++;
			} else
				trusted[j] = false;
		}
		bool contradiction = false;
		for (int j = 0; j < n; j++) {
			if (!trusted[j])
				continue;
			for (auto e : G[j]) {
				if ((trusted[e.first] && e.second == 0)||
						(!trusted[e.first] && e.second == 1)) {
					contradiction = true;
					goto fin;
				}
			}
		}
fin:
		;
		if (!contradiction) {
			if (max_ans < count)
				max_ans = count;
		}

	}
	cout << max_ans << endl;
	return 0;
}