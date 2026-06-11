#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

int main() {
    int n;
    scanf("%d", &n);
    vector<long> a(n+1);
    rep(i, n+1) {
        cin >> a[i];
    }
    vector<long> b(n);
    rep(i, n) {
        cin >> b[i];
    }
    long cnt = 0;
    rep(i, n) {
        if (a[i] + a[i+1] < b[i]) {
            cnt += a[i] + a[i+1];
            a[i] = 0;
            a[i+1] = 0;
        } else {
            cnt += b[i];
            if (a[i] > b[i]) {
                a[i] -= b[i];
            } else {
                a[i+1] -= b[i] - a[i];
                a[i] = 0;
            }
        }
    }
    cout << cnt << endl;
}