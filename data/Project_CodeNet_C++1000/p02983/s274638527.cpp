#include <iostream>
#include <vector>
using namespace std;

int main() {
	long long l, r;
	cin >> l >> r;
	if(l % 2019 == 0)
		return cout << l, 0;
	vector<int> v;
	for(int i = l; i <= r; ++i) {
		if(i % 2019 < l % 2019)
			return cout << i % 2019, 0;
		v.push_back(i % 2019);
	}
	int mini = 1e9;
	for(int x : v) {
		for(int y : v) {
			if(x == y)
				continue;
			mini = min(mini, x * y % 2019);
		}
	}
	cout << mini;
}
