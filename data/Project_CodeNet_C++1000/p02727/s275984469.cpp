#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

const int mxN = 1e5 + 5;
int color[mxN], red[mxN], green[mxN];

int main() {
	int n, m, r, g, c;
	cin >> n >> m >> r >> g >> c;
	for(int i = 0; i < r; ++i)
		cin >> red[i];
	for(int i = 0; i < g; ++i)
		cin >> green[i];
	for(int i = 0; i < c; ++i)
		cin >> color[i];
	sort(red, red + r, greater<int>());
	sort(green, green + g, greater<int>());
	sort(color, color + c, greater<int>());
	long long ans = 0;
	priority_queue<int> pq;
	vector<int> v;
	for(int i = 0; i < n; ++i)
		v.push_back(red[i]);
	for(int i = 0; i < m; ++i)
		v.push_back(green[i]);
	for(int i = 0; i < c; ++i)
		v.push_back(color[i]);
	sort(v.begin(), v.end(), greater<int>());
	for(int i = 0; i < n + m; ++i)
		ans += v[i];
	cout << ans;
}
