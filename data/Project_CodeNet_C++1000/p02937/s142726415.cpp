#include "bits/stdc++.h"
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std; 
typedef pair<int, int> P;

int main() {
	string S, T;
	cin >> S >> T;
	string S2 = S + S;
	long long ans = -1;
	for (int n = 0;n<T.size();++n) {
		string S3 = S2.substr((1 + ans)%S.size());
		int anstmp = S3.find(T[n]);
		if (string::npos == anstmp) {
			cout <<"-1" <<endl;
			return 0;
		}
		ans += (long long)anstmp + 1;
	}
	cout << ans + 1 <<endl;
	return 0;
} 