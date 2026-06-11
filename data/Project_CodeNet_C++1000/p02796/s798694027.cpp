#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int n; int ans; int t;
vector <pair<int, int>> v;

int main() {

	
	cin >> n;
	v.resize(n);
	
	for (int i = 0; i < n; i++) {
		int c, l;
		cin >> c >> l;
		v[i].second = c - l; v[i].first = c + l;
	}

	sort(v.begin(), v.end());

	t = -10000000000;


	for (int i = 0; i < n; i++) {
		if (t <= v[i].second) {
			ans++;
			t = v[i].first;
		}
	}

	cout << ans << endl;

}