#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	vector<int> A(n);
	ll res = 0;
	int cur_max = 0;
	for (int i = 0; i < n; ++i) {
		cin >> A[i];
		cur_max = max(cur_max, A[i]);
		res += cur_max - A[i];
	}
	cout << res << '\n';

	return 0;
}

