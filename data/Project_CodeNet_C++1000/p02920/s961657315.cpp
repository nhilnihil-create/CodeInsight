#include "bits/stdc++.h"
using namespace std;
const int INF = 1 << 30;

int main() {
	int N;
	cin >> N;
	int count = 1 << N;
	vector<int>S(count);
	for (int i = 0; i < count; ++i) {
		cin >> S[i];
	}
	sort(S.rbegin(), S.rend());
	vector<int>T;
	T.push_back(S[0]);
	S[0] = -1;
	for (int i = 0; i < N; ++i) {
		sort(T.rbegin(), T.rend());
		int memo = 0;
		int tsize = T.size();
		for (int j = 0; j < tsize; ++j) {
			bool b = false;
			for (; memo < count; ++memo) {
				if (-1 == S[memo]) {
					continue;
				}
				if (S[memo] < T[j]) {
					T.push_back(S[memo]);
					S[memo] = -1;
					b = true;
					break;
				}
			}
			if (!b) {
				cout << "No" << endl;
				return 0;
			}
		}
	}
	cout << "Yes" << endl;
	return 0;
}

