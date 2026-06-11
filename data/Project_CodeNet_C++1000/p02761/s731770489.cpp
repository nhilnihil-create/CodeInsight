#include<bits/stdc++.h>
using namespace std;
int n, m;
int s, c;
int num[4];
bool mark[4];
int main() {
	cin >> n >> m;
	if (m == 0) {
		if (n == 1) puts("0");
		else {
			cout << 1;
			for (int i = 2; i <= n; i++) cout << 0;
		}
		return 0;
	}
	for (int i = 1; i <= m; i++) {
		cin >> s >> c;
		if (s == 1 && c == 0 && n != 1) {
			puts("-1");
			return 0;
		}
		if (mark[s]) {
			if (num[s] != c) {
				puts("-1");
				return 0;
			}
		} else {
			num[s] = c;
			mark[s] = 1;
		}
	}
	if (!mark[1]) num[1] = 1;
	for (int i = 1; i <= n; i++) cout << num[i];
	return 0;
}