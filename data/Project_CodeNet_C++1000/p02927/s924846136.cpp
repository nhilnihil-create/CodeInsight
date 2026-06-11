#include <bits/stdc++.h>
using namespace std;
int main() {
	int M, D;
	 cin >> M >> D;
	 int ans = 0;
	for (int i = 1; i <= M; i++) {
		for (int d10 = 2; d10*10 <= D; d10++) {
			for (int d1 = 2; d1 <= 9 && d10*10+d1 <= D; d1++) {
				if (i == d1*d10) ans++;
			}
		}
	}
	cout << ans << endl;
}