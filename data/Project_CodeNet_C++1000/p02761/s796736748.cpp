#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
	int N, M;
	cin >> N >> M;

	vector<int> s(M);
	vector<int> c(M);

	for (int i = 0; i < M; ++i) {
		cin >> s[i] >> c[i];
	}

	int num = 1;
	for (int i = 1; i < N; ++i) {
		num *= 10;
	}
 
	int ans = num * 10;
	int end = num * 10;
	if (num == 1) num = 0;
	for (int i = num; i < end; ++i) {
		bool flag = true;
		string digit = to_string(i);
		for (int j = 0; j < M; ++j) {
			if (digit[s[j] - 1] != '0' + c[j]) {
				flag = false;
				break;
			}
		}
		if (flag) {
			ans = min(ans, i);
		}
	}
	cout << (ans == end ? -1 : ans) << endl;
	return 0;
}
