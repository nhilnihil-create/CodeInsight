#include <iostream>
using namespace std;

long long Calc(string S, int st, int ed) {
	int renzoku = 0;
	long long ans = 0;
	for (auto itr = S.begin() + st; itr != S.end() - ed - 1; itr++) {
		if (*itr == *(itr + 1)) renzoku++;
		else {
			ans += (renzoku + 1) / 2;
			renzoku = 0;
		}
	}
	ans += (renzoku + 1) / 2;
	return ans;
}

int main() {
	string S;
	int K;
	cin >> S >> K;
	long long ans = 0;
	if (S.front() != S.back()) cout << Calc(S, 0, 0) * K << endl;
	else {
		long long lrenzoku = 0, rrenzoku = 0;
		auto itr = S.begin();
		while (itr != S.end() && *itr == *S.begin()) {
			lrenzoku++;
			itr++;
		}
		itr = S.end() - 1;
		while (itr != S.begin() && *itr == *(S.end() - 1)) {
			rrenzoku++;
			itr--;
		}
		if (lrenzoku + rrenzoku < S.length()) {
			ans = lrenzoku / 2 + (lrenzoku + rrenzoku) / 2 * ((long long)K - 1) + rrenzoku / 2;
			cout << ans + Calc(S, lrenzoku, rrenzoku) * K << endl;
		}
		else cout << S.length() * K / 2 << endl;
	}
}
