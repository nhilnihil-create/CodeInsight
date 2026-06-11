#include "bits/stdc++.h"
using namespace std;

int main() {
	int N;
	cin >> N;
	map<string, int>mp;
	for (int n = 0; n < N; ++n) {
		string S;
		cin >> S;
		sort(S.begin(),S.end());
		mp[S]++;
	}
	long long ans = 0;
	auto begin = mp.begin(), end = mp.end();
	for (auto iter = begin; iter != end; iter++) {
		ans += (long long)iter->second*(iter->second-1)/2;
	}
	cout << ans <<endl;
	return 0;
}
