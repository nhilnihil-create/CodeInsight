#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    vector<int> a(n+1);
    for (size_t i = 0; i < n+1; i++) cin >> a[i];
    vector<int> b(n);
    for (size_t i = 0; i < n; i++) cin >> b[i];

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        int c;
        c = min(a[i], b[i]);
        a[i] -= c;
        ans += c;

        c = min(a[i+1], b[i]-c);
        a[i+1] -= c;
        ans += c;
    }

    cout << ans << endl;
    return 0;
}
