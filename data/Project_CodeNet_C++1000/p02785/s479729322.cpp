#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    long long n, k, *h; cin >> n >> k;
    h = new long long[n];
    for (int i = 0; i < n; i++)
        cin >> h[i];

    sort(h, h+n);
    long long ans = 0;
    for (int i = 0; i < n-k; i++)
        ans += h[i];

    cout << ans << endl;
    return 0;
}