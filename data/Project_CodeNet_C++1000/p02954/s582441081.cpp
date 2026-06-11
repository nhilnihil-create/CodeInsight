#include "bits/stdc++.h"
using namespace std;
int main() {
	string S;
	cin >> S;
	int R = 0;
	int L = 0;
	vector<pair<int, int>>VP;
	for (int n = 0; n < S.size() ; ++n) {
		if ('L' == S[n]) {
			L++;
		}
		else {
			if (0 != n) {
				if ('L' == S[n - 1]) {
					VP.push_back(make_pair(R,L));
					R = 0;
					L = 0;
				}
			}
			R++;
		}
	}
	VP.push_back(make_pair(R, L));
	vector<int>A(S.size());
	int now = 0; 
	for (int n = 0;n<VP.size();++n) {
		for (int m = 0; m < VP[n].first;++m) {
			if (m == VP[n].first-1) {
				A[now] += VP[n].first/2 + VP[n].first % 2;
				A[now] += VP[n].second / 2;
			}
			now++;
		}
		for (int m = 0; m < VP[n].second;++m) {
			if (m == 0) {
				A[now] += VP[n].first / 2;
				A[now] += VP[n].second / 2 + VP[n].second % 2;
			}
			now++;
		}
	}
	for (int n = 0;n< A.size(); ++n) {
		if (0 != n) {
			cout << " ";
		}
		cout << A[n];
	}
	return 0;
}