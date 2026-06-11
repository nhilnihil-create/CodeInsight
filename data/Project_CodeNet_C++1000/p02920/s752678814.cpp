#include <bits/stdc++.h>

using namespace std;

const int maxn = (1 << 18);

int a[maxn + 1];
int usd[maxn];

int main() {
	int k; cin >> k;
  	int n = (1 << k);
  	for (int i = 0; i < n; i++)
    	cin >> a[i];
  	sort(a, a + n);
  	for (int i = 0; i < n; i++)
      	usd[i] = -1;
	usd[n - 1] = 0;
	for (int q = 0; q < k; q++) {
        int l = n - 1, r = n - 1, cnt = 0;
        while (r >= 0) {
            if (usd[l] == -1 || usd[l] == q + 1) {
                l--; r = min(l, r);
                continue;
            }
            if (usd[r] == -1 && a[l] != a[r]) {
                ++cnt; usd[r] = q + 1;
                --l; --r; continue;
            }
            --r;
        }
        if (cnt < (1 << q)) {
            cout << "No";
            return 0;
        }
    }
  	cout << "Yes";
  	return 0;
}
