#include "bits/stdc++.h"
using namespace std;

int main() {
	int N;
	cin >> N;
	string S;
	cin >> S;
	int ans = 0;
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {
			for (int k = 0; k < 10; ++k) {
				int count = 0;
				vector<int>X = {i,j,k};
				for (int l = 0;l<S.size();++l) {
					if ((X[count]+'0') == S[l]) {
						count++;
					}
					if (3 == count) {
						ans++;
						break;
					}
				}
			}
		}
	}
	cout << ans <<  endl;
	return 0;
}
