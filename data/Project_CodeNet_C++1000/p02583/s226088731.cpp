#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int n; cin >> n;
	vector<int>L(n); for (auto&& x : L)cin >> x;

	int ans = 0;
	for (int i = 0; i < n - 2; i++) {
		for (int j = i + 1; j < n - 1; j++) {
			if (L[i] == L[j])continue;
			for (int k = j + 1; k < n; k++) {
				if (L[i] == L[k] || L[j] == L[k])continue;
				vector<int>tmp(3);
				tmp[0] = L[i]; tmp[1] = L[j]; tmp[2] = L[k];
				sort(tmp.begin(), tmp.end());
				if (tmp[0] + tmp[1] > tmp[2])ans++;
			}
		}
	}
	cout << ans << endl;

	return 0;
}