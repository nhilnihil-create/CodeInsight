#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<sstream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<cmath>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<numeric>
#include<functional>
#include<algorithm>
#include<bitset>
#include<tuple>
#include<unordered_set>
#include<unordered_map>
#include<random>
#include<array>
#include<cassert>
using namespace std;
#define INF (1<<29)
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define all(v) v.begin(),v.end()
#define uniq(v) v.erase(unique(all(v)),v.end())

#define MOD 1000000007




int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	string s;
	cin >> n >> s;

	if (s[0] == 'W') {
		cout << 0 << endl;
		return 0;
	}

	vector<int> d(s.size());
	d[0] = 1;
	for (int i = 1; i < s.size();i++) {
		if (s[i-1] == s[i]) {
			d[i] = 1 - d[i - 1];
		}
		else {
			d[i] = d[i - 1];
		}
	}
	long long ans = 1, r = 0;

	rep(i, s.size()) {
		if (d[i] == 0) {
			if (r == 0) {
				ans = 0;
				break;
			}
			ans *= r;
			ans %= MOD;
			r--;
		}

		r += d[i];
	}
	if (r)ans = 0;

	rep(i, n) (ans *= i + 1) %= MOD;

	cout << ans << endl;



	return 0;
}