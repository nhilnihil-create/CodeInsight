#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

void Zalgorithm(string s, vector <int>& Z, int i, int j) {
	while (i < s.size()) {
		while ((i + j < s.size()) && (s[j] == s[i+j]) ) { ++j; }
		Z[i] = j;
		if (j == 0){ ++i; continue; }
		int k = 1;
		while ((i + k < s.size()) && (k + Z[k] < j) ) { Z[i+k] = Z[k]; ++k; }
		i += k; j -= k;
	}
}

int main() {
	int N;
	cin >> N;
	string S;
	cin >> S;

	int ans = 0;
	for (int ii = 0; ii < N-1; ++ii){
		int size = N - ii;
		vector <int> Z(size);
		Z[0] = size;
		string sub = S.substr(ii);
		Zalgorithm(sub, Z, 1, 0);

		int val = 0;
		for (int jj = 0; jj < size; ++jj){
			int tmp = min(jj, Z[jj]);
			val = max(val, tmp);
		}
		ans = max(ans, val);
	}

	cout << ans << "\n";

	return 0;
}
