#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int64_t N;
	cin >> N;
	string ans;
	--N;
	if (N == 0) {
		cout << "a" << endl;
		return 0;
	}
	while (N) {
		// cout << N << endl;
		ans.push_back('a' + ((N)%26));
		N /= 26;
		if (N == 1) {
			ans.push_back('a');
			break;
		}
		if (N>1) --N;
	}

	reverse(ans.begin(), ans.end());

	cout << ans << endl;
}