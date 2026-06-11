#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
int N, K;
char s[MAXN];
int main() {
	cin >> N >> K;
	cin >> (s + 1);
	int M = 0, ANS = 0;
	for (int i = 1; i <= N; ++ i)
		if (s[i] != s[i - 1])
			++ M;
		else
			++ ANS;
	if (M == 1) {
		cout << ANS << endl;
		return 0;
	}
	int n1 = min(M / 2, K);
	cout << min(ANS + n1 * 2, N - 1) << endl;
	return 0;
}