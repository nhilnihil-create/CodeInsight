#include <iostream>
#include <utility>
#include <string>
#include <vector>
using namespace std;

int main() {
	int n, q;
	cin >> n >> q;
	vector<pair<int, int>> v;
	while(q--) {
		int x, y;
		cin >> x >> y;
		v.push_back({x, y});
	}
	for(int i = 0; i <= 1000; ++i) {
		string s = to_string(i);
		if((int)s.size() == n) {
			bool ok = true;
			for(pair<int, int> x : v) {
				if(s[x.first - 1] - '0' != x.second) {
					ok = false;
					break;
				}
			}
			if(ok)
				return cout << i, 0;
		}
	}
	cout << -1;
}
