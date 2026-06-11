#include "bits/stdc++.h"
using namespace std;

int main() {
	int N , L;
	cin >> N>>L; 
	int ans = 0;
	int tmp =1000000;
	int minmemo = 100000;
	for (int n = 0;n<N;++n) {
		ans += L + n;
		if (abs(tmp) > abs(L+n)) {
			tmp = L + n;
		}
	}
	ans -= tmp;

	cout << ans << endl;
	return 0;
}