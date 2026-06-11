#include "bits/stdc++.h"

using namespace std;
int main() {
	int N,M;
	cin >> N>> M;
	vector<bool>B(N + 1); 
	vector<int>C(N + 1);
	int ans = 0;
	int pena = 0;

	for (int n = 0;n<M;++n) {
		int p;
		string s;
		cin >> p >> s;
		if ("AC" == s && false == B[p]) {
			ans++;
			pena+=C[p];
			B[p] = true;
		}
		else if ("WA" == s && false == B[p]) {
			C[p]++;
		}
		else if ("WA" == s && true == B[p]) {
			//
		}
		else {
		}
	}
	cout << ans  << " "<<pena<<  endl;
	return 0;
}
