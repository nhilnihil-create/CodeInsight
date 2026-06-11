#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define rep(i,n) for (int i = 0; i < (n); i++)
const ll mod = 1000000007;

int main() {
    int n; cin >> n;
    int a[n]; rep(i,n) cin >> a[i];
    rep(i,n) {
        rep(j,i) {
            swap(a[i],a[j]);
            int b = 1;
            rep(k,n-1) {
                if (a[k] >= a[k+1]) {
                    b = 0;
                    break;
                }
            }
            if (b) {
                cout << "YES" << endl;
                return 0;
            }
            swap(a[i],a[j]);
        }
    }
    rep(i,n-1) {
        if (a[i] >= a[i+1]) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}
