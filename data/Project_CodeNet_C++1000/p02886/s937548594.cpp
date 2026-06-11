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
        for (int j=i+1; j < n; j++) {
            sum += d[i] * d[j];
        }
    }

    cout << sum << endl;

	return 0;
}
