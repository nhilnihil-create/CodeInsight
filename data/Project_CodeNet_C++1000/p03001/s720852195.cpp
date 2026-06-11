#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define PB push_back
#define MP make_pair

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
    int w, h, x, y; cin >> w >> h >> x >> y;
    cout << setprecision(10) << double(w) * double(h) / 2 << " " << (2 * x == w && 2 * y == h) << "\n";
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* print new lines
*/