#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;  cin >> n;
    vector<long long> a(n);
    long long ans = 0;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end(), greater<long long>());
    if (n % 2) {
        ans += a[0];
        for (int i = 1; i < n/2; i++)
            ans += a[i] * 2;
        ans += a[n/2];
    }
    else {
        for (int i = 1; i <= n/2-1; i++)
            ans += a[i] * 2;
        ans += a[0];
    }

    cout << ans << endl;
    return 0;
}