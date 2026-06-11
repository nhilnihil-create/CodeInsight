#include "bits/stdc++.h"
using namespace std;

int main() {
	string S; cin >> S;
	vector<long long>Bigger(S.size() + 1, 0), Less(S.size() + 1, 0);
	for (long long i = 0; i < S.size(); i++) {
		if (S.at(i) == '<') {
			Less.at(i + 1) = Less.at(i) + 1;
		}
	}
	for (long long i = S.size() - 1; i >= 0; i--) {
		if (S.at(i) == '>') {
			Bigger.at(i) = Bigger.at(i + 1) + 1;
		}
	}
	long long ans = 0;
	for (long long i = 0; i <= S.size(); i++) {
		ans += max(Less.at(i), Bigger.at(i));
	}
	cout << ans << endl;
}