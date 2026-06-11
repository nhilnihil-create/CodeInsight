#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int a[100005];

int main() {
    int n;
    cin >> n;
    ll h[n];
    rep(i, n) cin >> h[i];

    for (int i = 1; i < n; i++) {
        a[i] += a[i - 1];
        if (h[i - 1] >= h[i])
            a[i]++;
        else
            a[i] = 0;
    }

    cout << *max_element(a, a + n) << endl;
    return 0;
}
