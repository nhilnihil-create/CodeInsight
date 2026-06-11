#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

ll solve() {
    int a, b, c, k; cin >> a >> b >> c >> k;
    if (k <= a) {
        return k;
    } else if (k <= a + b) {
        return a;
    } else if (k < a + b + c) {
        return a - 1 * (k - a - b); 
    } else {
        return a - c;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	cout << solve() << endl;
}
