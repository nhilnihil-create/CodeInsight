#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define rep(i,n) for (int i = 0; i < (n); i++)
const ll mod = 1000000007;

int main() {
    int n;
    cin >> n;
    int a[n];
    rep(i,n) cin >> a[i];

    int m = 0;
    int idx = -1;
    int c = 0;
    rep(i,n) {
        if (m < a[i]) {
            m = a[i];
            idx = i;
            c = 0;
        }
        else if (m == a[i]) {
            c++;
        }
    }
    if (c) {
        rep(i,n) {
            cout << m << endl;
        }
    } else {
        int m2 = 0;
        rep(i,n) {
            if (a[i] != m) m2 = max(m2,a[i]);
        }
        rep(i,n) {
            if (i != idx) cout << m << endl;
            else cout << m2 << endl;
        }
    }
    return 0;
}
