#include <iostream>
#include <vector>
#include <array>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <string>
#include <sstream>
#include <algorithm>
#include <random>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <cassert>
#include <climits>
#include <bitset>
#include <functional>
#include <iomanip>
#include <random>

#define FOR_LT(i, beg, end) for (int i = (int)(beg); i < (int)(end); i++)
#define FOR_LE(i, beg, end) for (int i = (int)(beg); i <= (int)(end); i++)
#define FOR_DW(i, beg, end) for (int i = (int)(beg); (int)(end) <= i; i--)
#define REP(n)              for (int repeat_index = 0; repeat_index < (int)n; repeat_index++)


using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout << fixed << setprecision(20);

	string s; cin >> s;
	string t;
	t.resize(s.size());
	FOR_LT(i, 0, s.size()) {
		t[i] = s[s.size() - i - 1];
	}

	int64_t ans = 0;
	bool has_c = false;
	FOR_LT(i, 0, t.size()) {
		int n = t[i] - '0';
		if (has_c) n++;
		if (n == 10) {
			has_c = true;
			continue;
		}
		if (n < 5) {
			ans += n;
			has_c = false;
		}
		else if (n == 5) {
			if (i < t.size() - 1 && '5' <= t[i + 1]) {
				has_c = true;
			}
			else {
				has_c = false;
			}
			ans += n;
		}
		else {
			ans += (10 - n);
			has_c = true;
		}
	}
	if (has_c) ans++;
	cout << ans << endl;

	return 0;
}

/*
int solve(string t) {
	int64_t ans = 0;
	bool has_c = false;
	FOR_LT(i, 0, t.size()) {
		int n = t[i] - '0';
		if (has_c) n++;
		if (n == 10) {
			has_c = true;
			continue;
		}
		if (n < 5) {
			ans += n;
			has_c = false;
		}
		else if (n == 5) {
			if (i < t.size() - 1 && '5' <= t[i + 1]) {
				has_c = true;
			}
			else {
				has_c = false;
			}
			ans += n;
		}
		else {
			ans += (10 - n);
			has_c = true;
		}
	}
	if (has_c) ans++;

	return ans;
}

int solve2(int n) {
	auto count = [](int i) {
		int c = 0;
		while (i != 0) {
			c += (i % 10);
			i /= 10;
		}
		return c;
	};

	int ans = INT_MAX;
	FOR_LT(i, n, 10 * n) {
		int ca = (count(i) + count(i - n));
		ans = min(ans, ca);
	}
	return ans;
}

int main()
{
	FOR_LE(i, 1, 10000) {
		string s = to_string(i);

		string t;
		t.resize(s.size());
		FOR_LT(i, 0, s.size()) {
			t[i] = s[s.size() - i - 1];
		}

		cout << s << " " << solve(t) << " " << solve2(i) << endl;
		if (solve(t) != solve2(i)) {
			cout << "!!!" << endl;
			return -1;
		}
	}
	return 0;
}
*/