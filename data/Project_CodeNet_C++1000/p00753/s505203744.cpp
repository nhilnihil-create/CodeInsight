#include <iostream>

#define REP(i, n) for (int i = 0; i < n; i++)
#define debug(x) cerr << #x << " = " << (x) << endl;

using namespace std;

int main() {
	while (1) {
		int furui[323456], n, ans;
		
		cin >> n;
		if (n==0) break;
		REP(i, 2*n+1) furui[i] = i;
		ans = 0;

		for (int i = 2; i <= 2 * n; i++) {
			if (furui[i] > 0) {
				//debug(i);
				if (i > n) ans++;
				for (int k = 1; i * k <= 2 * n; k++) {
					furui[i * k] = 0;
				}
			}
		}

		cout << ans << endl;
	}
	return 0;
}

