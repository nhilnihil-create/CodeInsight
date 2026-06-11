#include "bits/stdc++.h"
using namespace std;
typedef pair<long long, long long> P;
int main() {
	string S, T; cin >> S >> T;
	long long ans = 0;
	for (long long i = 0; i < S.size(); i++) {
		if (S.at(i) == T.at(i)) ans++;
	}
	cout << ans << endl;
}