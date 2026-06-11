#include "bits/stdc++.h"
using namespace std;

int main() {
	int N;
	cin >> N;  
	string S;
	cin >> S;
	int ans = 1;
	for (int n = 1;n < S.size();++n) {
		if (S[n-1] != S[n]) {
			++ans;
		}
	}
	cout << ans << endl;
	return 0;
}
