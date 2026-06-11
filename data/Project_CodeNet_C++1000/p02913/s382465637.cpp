#include <iostream>
#include <vector>
using namespace std;

vector<int> z_algorithm(string s) {
	int l = s.size();
	vector<int> Z(l);
	Z[0] = l;
	for (int i = 1, j = 0; i < l;) {
		while (i+j < l && s[j] == s[i+j]) ++j;
		Z[i] = j;
		if (j == 0) {++i; continue;}
		int k = 1;
		while (i+k < l && k + Z[k] < j) {
			Z[i+k] = Z[k];
			++k;
		}
		i += k; j -= k;
	}
	return Z;
}

int main() {
	int n;
	string s;
	cin >> n >> s;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		auto Z = z_algorithm(s.substr(i, n-i));
		for (int j = 1; j < Z.size(); j++) {
			int now = min(j, Z[j]);
			ans = max(ans, now);
		}
	}
	cout << ans << endl;
	return 0;
}