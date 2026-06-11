
// A - XOR Circle

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

int main() {
	int N;
	cin >> N;

	map<int, int> A;

	for (int i=0; i<N; i++) {
		int a;
		cin >> a;
		A[a]++;
	}

	vector<int> a;
	vector<int> cnt;
	for (auto itr : A) {
		a.push_back(itr.first);
		cnt.push_back(itr.second);
	}

	string ans = "Yes";
	if (a.size() == 1) {
		if (a[0] != 0) ans = "No";
	} else if (a.size() == 2) {
		if (a[0] != 0) ans = "No";
		if (cnt[0] * 2 != cnt[1]) ans = "No";
	} else if (a.size() == 3) {
		if (cnt[0] != cnt[1] || cnt[1] != cnt[2] || cnt[2] != cnt[0]) ans = "No";
		if ((a[0] ^ a[1] ^ a[2]) != 0) ans = "No";
	} else {
		ans = "No";
	}

	cout << ans << endl;

	return 0;
}