#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using P = pair<int, int>;

int main() {
	int n;
	int d[15][15];
	rep(i, 15) rep(j, 15) d[i][j] = -1;

	// Ai番目の人の人が各Aj番目の人の情報(1:正直/0:不親切)を入力.
	cin >> n;
	rep (i, n) {
		int a;
		cin >> a;
		rep(j , a) {
			int x;
			cin >> x;
			cin >> d[i][x-1];
		}
	}

	int ans = 0;
	for (int bit=0; bit<(1<<n); bit++) {
		int false_cnt = 0;
		bool s[15];
		rep (i, 15) s[i] = true;
		/* bit立っているAiの情報を無視する場合. */
		for (int i=0; i<n; i++) {
			if (bit & (1<<i)) {
				s[i] = false;
				false_cnt++;
			}
		}
		bool pat_res = true;
		rep (i, n) {
			if (s[i] == false) continue;
			rep (j, n) {
				if (d[i][j] == -1) {
					/*Ajの評価もってない.*/
					continue;
				} else if ((d[i][j] == 1) && (s[j] == true)) {
					/**/
				} else if ((d[i][j] == 0) && (s[j] == false)) {
					/**/
				} else {
					/* このパターンはだめ. */
					pat_res = false;
				}
			}
		}
		if (pat_res == true) {
//			cout << "true" << endl;
//			cout << "n = " << n << endl;
//			cout << "false_cnt = " << false_cnt << endl;
			ans = max(ans, n-false_cnt);
		}
	}

	cout << ans << endl;

	return 0;
}
