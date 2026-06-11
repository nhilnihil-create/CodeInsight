#include <bits/stdc++.h>

using namespace std;


int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    long long ans = 0;
    for(int i = 0; i < n - 1; i++) {
        int h = (i + 1) / 2;
        ans += a[n-h-1];
    }
    cout << ans << "\n";
    return 0;
}