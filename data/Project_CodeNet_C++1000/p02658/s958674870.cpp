#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int64_t N;
    cin >> N;
    int64_t a, r = 1, ee = 1e18;
    vector<int64_t> arr;
    bool z = 0;
    for (int i = 0; i < N; ++i) {
    	cin >> a;
    	if (a == 0) {
    		z = 1;
    	}
    	arr.push_back(a);
    }
    if (z) {
    	cout << 0 << endl;
    	return 0;
    }
    for (int64_t a : arr) {
    	if (a > ee/r) {
    		cout << -1 << endl;
    		return 0;
    	}
    	r *= a;
    }
    cout << r << endl;
}