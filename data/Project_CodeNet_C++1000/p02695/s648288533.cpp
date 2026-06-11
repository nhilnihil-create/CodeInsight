#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, m, q, ret = 0;
int a[51], b[51], c[51], d[51];

void construct(int curr_val, vector<int> curr_set) {
	curr_set.push_back(curr_val);
	if ((int) curr_set.size() >= n) {
		int temp = 0;
		for (int i = 0; i<q; i++) {
			if (curr_set[b[i] -1] - curr_set[a[i] - 1] == c[i]) temp += d[i];
		}
		ret = max(ret, temp);
	}
	else  {
		for (int val = curr_val; val <= m; val++) construct(val, curr_set);
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> q;
	for (int i = 0; i<q; i++) {
		cin >> a[i] >> b[i] >> c[i] >> d[i];
	}
	for (int val = 1; val <= m; val++) construct(val, {});
	cout << ret << '\n';
}

