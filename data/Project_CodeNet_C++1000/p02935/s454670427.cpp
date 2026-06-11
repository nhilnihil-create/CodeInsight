#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

int main() {
    int n;
    scanf("%d", &n);
    vector<int> v(n);
    rep(i, n) {
        scanf("%d", &v[i]);
    }
    sort(v.rbegin(), v.rend());
    double ans;
    rep(i, n) {
        if (i != n-1) ans += v[i] / pow(2, i+1);
        else ans += v[i] / pow(2, n-1);
    }
    cout << ans << endl;
}