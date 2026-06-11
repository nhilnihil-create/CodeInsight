#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)cin >> a[i];
    sort(a.begin(), a.end(), greater<>());

    long long ret = a[0];
    int remain = n - 2;
    for (int i = 1; i < n; i++) {
        int x = min(2, remain);
        ret += a[i] * x, remain -= x;
    }

    cout << ret << endl;
    return 0;
}