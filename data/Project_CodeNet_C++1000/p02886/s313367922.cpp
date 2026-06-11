#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using P = pair<int, int>;

int main() {
	int n;
    cin >> n;
    int d[n];

    rep (i, n) cin >> d[i];

    int sum  = 0;
    rep (i, n) {
        rep (j, n) {
            if (i != j) sum += d[i] * d[j];
        }
    }

    cout << sum / 2 << endl;

	return 0;
}
