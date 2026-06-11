#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii; 
const int N = 2e5+10, mod = 1e9+7;

void solve() {
    int k, a, b; cin >> k >> a >> b;
    int c = k;
    while (1) {
        if (k > b) {
            k -= c;
            break;
        } else {
            k += c;
        }
    }

    (k >= a && k <= b) ? cout << "OK\n" : cout << "NG\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t = 1; 
    // cin >> t;
    while (t--) solve();
    return 0;
}
