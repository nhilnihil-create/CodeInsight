#include <bits/stdc++.h>
using namespace std;
#define vec(type) vector<type>

int main() {
    int n, k;
    cin >> n >> k;
    vec(int) h(n);
    for (int i = 0; i < n; i++) cin >> h[i];

    sort(h.begin(), h.end());
    reverse(h.begin(), h.end());
    for (int i = 0; i < min(k, n); i++) {
        h[i] = 0;
    }

    long long ans = accumulate(h.begin(), h.end(),0LL);
    cout << ans << endl;
}
