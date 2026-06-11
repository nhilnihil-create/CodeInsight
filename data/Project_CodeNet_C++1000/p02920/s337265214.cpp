#include <bits/stdc++.h>
using namespace std;

void compress(vector<int>& v) {
	auto vs = v;
	sort(vs.begin(), vs.end());
	vs.erase(unique(vs.begin(), vs.end()), vs.end());
	for (auto& val : v) {
		val = lower_bound(vs.begin(), vs.end(), val) - vs.begin();
	}
}

int main()
{
	int N;
	cin >> N;
	vector<int> S(1 << N);
	for (int i = 0; i < (1 << N); i++) {
		cin >> S[i];
	}
	compress(S);
	sort(S.rbegin(), S.rend());
	if (count(S.begin(), S.end(), S[0]) > 1) {
		puts("No");
		return 0;
	}
	const int M = S[0] + 1;
	vector<int> cnt(M + 1);
	for (int i = 0; i < (1 << N); i++) {
		cnt[S[i]]++;
	}
	vector<int> dp(N, 1);
	bool ng = false;
	for (int i = M - 2; i >= 0; i--) {
		auto tmp = dp;
		for (int j = 0; j < cnt[i]; j++) {
			bool ok = false;
			for (int k = N - 1; k >= 0; k--) if (tmp[k] > 0) {
				--tmp[k], --dp[k];
				for (int l = 0; l < k; l++) {
					++dp[l];
				}
				ok = true;
				break;
			}
			if (!ok) {
				ng = true;
			}
		}
	}
	puts(ng ? "No" : "Yes");
	return 0;
}
