#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;
const int INF = INT_MAX;

int main() {
	string S;
	cin >> S;

	vector<int> v(S.size(), 0);
	char f = 'R';
	int cnt = 0;

	for (int i = 0; i < S.size(); i++) {
		char ch = S[i];
		if (ch == 'R') cnt++;
		else {
			v[i] += cnt / 2;
			v[i - 1] += cnt - (cnt / 2);
			cnt = 0;
		}
	}

	cnt = 0;
	for (int i = S.size() - 1; i >= 0; i--) {
		char ch = S[i];
		if (ch == 'L') cnt++;
		else {
			v[i] += cnt / 2;
			v[i + 1] += cnt - (cnt / 2);
			cnt = 0;
		}
	}

	for (int i = 0; i < S.size(); i++) {
		if (i) cout << ' ';
		cout << v[i];
	}
	cout << endl;
}