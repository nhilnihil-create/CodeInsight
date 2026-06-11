#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <functional>
#include <queue>
using namespace std;

string S;
long long cur[1 << 18], power[1 << 18];
long long cnt[1 << 18];

int main() {
	cin >> S;
	power[0] = 1;
	for (int i = 1; i <= 250000; i++) power[i] = (10LL * power[i - 1]) % 2019LL;
	
	cur[S.size()] = 0;
	for (int i = S.size() - 1; i >= 0; i--) {
		cur[i] = (cur[i + 1] + 1LL * (S[i] - '0') * power[S.size() - 1 - i]) % 2019LL;
	}

	long long ret = 0;
	for (int i = 0; i <= S.size(); i++) {
		ret += cnt[cur[i]];
		cnt[cur[i]]++;
	}
	cout << ret << endl;
	return 0;
}