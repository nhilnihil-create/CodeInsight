#include "bits/stdc++.h"
using namespace std;

int main() {
	string S;
	cin >>S;
	int ans = 0;
	for (int n = 0;n<S.size()/2;++n) {
		if (S[n] != S[S.size()-1-n]) {
			ans++;
		}
	}
	cout << ans <<endl;
	return 0;
}