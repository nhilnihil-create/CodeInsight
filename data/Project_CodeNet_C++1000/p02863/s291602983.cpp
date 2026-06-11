#include<bits/stdc++.h>
typedef long double ld;
typedef long long ll;
 
using namespace std;
 
#define MAXN (1 << 12)
 
int n, t;
vector<pair<int, int> > v;
int mem[MAXN][MAXN];
 
int solve(int k, int pos) {
	if ((k >= t) || (pos >= n)) {
		return 0;
	}
	int & ret = mem[k][pos];
	if (ret >= 0) {
		return ret;
	}
	int cur1 = v[pos].second + solve(k + v[pos].first, pos + 1);
	int cur2 = solve(k, pos + 1);
	ret = max(cur1, cur2);
	return ret;
}
 
int main() {
	memset(mem, -1, sizeof(mem));
	cin >> n >> t;
	for (int i = 0; i < n; i++) {
		int t1, t2;
		cin >> t1 >> t2;
		v.push_back(make_pair(t1, t2));
	}
	sort(v.begin(), v.end());
	cout << solve(0, 0) << endl;
	return 0;
}