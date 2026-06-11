#include "bits/stdc++.h"
using namespace std;

int main() {
	string N;
	cin >> N;
	vector<int>Num(N.size());
	for (int n = 0; n < N.size(); ++n) {
		Num[n] = N[n] - '0';
	}
	reverse(Num.begin(),Num.end());
	vector<int>DP0(N.size());//ぴったし
	vector<int>DP1(N.size());//くりあがり
	for (int n = 0;n<N.size();++n) {
		if (0 == n) {
			DP0[n] = Num[n];
			DP1[n] = 10 - Num[n];
		}
		else {
			if (9 == Num[n]) {
				DP0[n] = Num[n]+DP0[n-1];//ここで破綻するから
				DP1[n] = min((10 - Num[n]) + DP0[n - 1], (9 - Num[n]) + DP1[n - 1]);
			}
			else {
				DP0[n] = min(Num[n] + DP0[n - 1], Num[n] + DP1[n - 1] + 1);
				DP1[n] = min((10 - Num[n]) + DP0[n - 1], (9 - Num[n]) + DP1[n - 1]);
			}
		}
	}
	cout << min(DP0[N.size()-1], 1 + DP1[N.size() - 1]) << endl;
	return 0;
}