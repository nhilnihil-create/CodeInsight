#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii; 
const int N = 2e5+10, mod = 1e9+7;

void solve() {
    ll a, b, k; cin >> a >> b >> k;

    ll c = min(a, k);
    a -= c;
    k -= c;
    cout << a << " ";

    if (k > 0) {
        if (b <= k) {
            b = 0;
        } else {
            b -= k;
        }  
    }
    cout << b << endl;
}   

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t = 1;
    while (t--) solve();
    return 0;
}
