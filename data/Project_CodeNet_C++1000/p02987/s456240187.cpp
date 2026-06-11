#include "bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

using namespace std;
const long long INF = 1LL << 61;
const int MOD = 2019;

int main() {
	string S; cin >> S;
	map<char, int> mp;
	rep(i, S.size())++mp[S[i]];
	if (mp.size() == 2) {
		for (auto itr = mp.begin(); itr != mp.end(); ++itr) {
			if (itr->second != 2) {
				cout << "No";
				return 0;
			}
		}
	}
	else {
		cout << "No";
		return 0;
	}
	cout << "Yes";
}