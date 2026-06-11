#include <algorithm>
#include <iostream>
#include <vector>
#include <string> 

typedef long long ll;
using namespace std;
const ll m = 1e9 + 7;

int main() {
	int n; cin >> n;
	vector<int>vec(n);
	for (int i = 0; i < n; ++i)
		cin >> vec[i];

	int mx = 0;
	ll res = 0;
	for (int i = 0; i < n; ++i) {
		mx = max(mx, vec[i]);
		int x = mx;
		res += x - vec[i];
	}
	cout << res << endl;
    return 0;
}