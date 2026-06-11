#include "bits/stdc++.h"
using namespace std;

int main() {
	string S;
	cin >> S;
	reverse(S.begin(), S.end());
	int n = S.size();
	vector<int>mod(2019);
	int now = 0;
	int ans = 0;
	int ten = 1;
	mod[0] = 1;
	for (int m = 0;m < n; ++m) {
		now += (S[m] - '0')*ten;
		now %= 2019;
		ans += mod[now];
		//cout << now << endl;
		mod[now]++;
		ten = (ten * 10) % 2019;
	}
	cout << ans <<endl;
	return 0;
}