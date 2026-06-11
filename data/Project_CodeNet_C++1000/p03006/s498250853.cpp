#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
#include<functional>
#include<algorithm>
#include<stdlib.h>
#include<string>
#include<string.h>
#define _USE_MATH_DEFINES
#include<math.h>
#include<deque>
#include<set>
#include<map>
#include<iostream>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(auto i=a;i<b;i++)
#define all(_x) _x.begin(), _x.end()
#define r_sort(_x) sort(_x.begin(), _x.end(), std::greater<int>())
#define vec_cnt(_a, _n) (upper_bound(all(_a), _n) - lower_bound(all(_a), _n))
#define R(_x, _y) (0 <= _x && _x <= M - 1 && 0 <= _y && _y <= N - 1)
#define A(a) (!(R(x + dx[a], y + dy[a]) && b[y + dy[a]][x + dx[a]]))
ll gcd(ll a, ll b) { return a % b == 0 ? b : gcd(b, a % b); }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }
#define INF 1 << 30
int main() {
	int N, C = 0, a, b, ans;
	cin >> N;
	vector<pair<int, int>> p(N);
	map<pair<int, int>, int> mp;
	rep(i, 0, N)cin >> p[i].first >> p[i].second;
	rep(i, 0, N) {
		rep(i2, 0, N) {
			if (i == i2)continue;
			mp[make_pair(p[i].first - p[i2].first, p[i].second - p[i2].second)]++;
		}
	}
	ans = N;
	for (auto it : mp) {
		//printf("%d\n", it.second);
		ans = min(ans, N - it.second);
	}
	printf("%d\n", ans);
	return 0;
}