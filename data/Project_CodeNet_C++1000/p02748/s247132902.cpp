#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

int main() {
	int a, b, m;
	cin >> a >> b >> m;
	vector<int> ref(a);
	vector<int> mic(b);
	for (int i = 0; i < a; i++) {
		cin >> ref[i];
	}
	for (int i = 0; i < b; i++) {
		cin >> mic[i];
	}
	vector<int> x(m);
	vector<int> y(m);
	vector<int> c(m);
	int j = *min_element(ref.begin(), ref.end());
	int h = *min_element(mic.begin(), mic.end());
	int ans = h + j;
	for (int i = 0; i < m; i++) {
		int x, y, c;
		cin >> x >> y >> c;
		x--, y--;
		ans = min(ans, ref[x] + mic[y] - c);
	}
	cout << ans;
}