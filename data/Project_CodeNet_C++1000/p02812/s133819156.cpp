#include "bits/stdc++.h"
using namespace std;

int main() {
	int N;
	string S;
	cin >> N >> S;
	int ans = 0;
	for (int n = 0;n< N - 2;++n) {
		if ((S[n] == 'A')&&(S[n+1] =='B')&&(S[n+2] == 'C')) {
			++ans;
		}
	}
	cout << ans << endl;
	return 0;
}