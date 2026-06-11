#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<int> a(n+1), b(n);
    ll count = 0;
    rep(i,n+1) {
        cin >> a[i];
        count += a[i];
    }
    rep(i,n) cin >> b[i];

    rep(i,n) {
        if (a[i] >= b[i]) {
            a[i] -= b[i];
            b[i] = 0;
        }
        else {
            b[i] -= a[i];
            a[i] = 0;
            if (a[i+1] >= b[i]) {
                a[i+1] -= b[i];
                b[i] = 0;
            }
            else {
                b[i] -= a[i+1];
                a[i+1] = 0;
            }
        }
    }

    ll count2 = 0;
    rep(i,n+1) {
        count2 += a[i];
    }

    cout << count - count2 << endl;


    return 0;
}