#include "bits/stdc++.h"
using namespace std;

int main() {
	string S,T;
	cin >> S >>T; 
	int ans = 0;
	for (int n = 0;n< S.size();++n) {
		if (S[n] == T[n]) {
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}