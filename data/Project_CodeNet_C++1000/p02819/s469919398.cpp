#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii; 
const int N = 2e5+10, mod = 1e9+7;

void solve() {
    int n; cin >> n;

    if (n == 2) {
        cout << 2 << endl;
        return;
    }
    
    while (1) {
        bool m = true;
        for (int i = 2; i * i <= n; ++i) {
            if (n % i == 0) {
                m = false;
                break;
            }
        }
        if (m) {
            cout << n << endl;
            return;
        }
        ++n;
    }
}   

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t = 1;
    while (t--) solve();
    return 0;
}
