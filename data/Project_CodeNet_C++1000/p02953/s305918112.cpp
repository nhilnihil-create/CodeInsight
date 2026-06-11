#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define rep(i,n) for (int i = 0; i < (n); i++)
const ll mod = 1000000007;

int main() {
    int n; cin >> n;
    ll h[n]; rep(i,n) cin >> h[i];
    
    ll m = 0;
    rep(i,n) {
        if (m > h[i]) {
            cout << "No" << endl;
            return 0;
        }
        else m = max(m,h[i]-1);
    }
    cout << "Yes" << endl;
    return 0;
}
