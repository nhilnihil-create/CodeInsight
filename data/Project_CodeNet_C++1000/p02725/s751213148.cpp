#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;

int main() {
    int k, n;
    cin >> k >> n;
    int *a = new int[n + 10];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int max = 0;
    for (int i = 0; i < n; i++) {
        if (i == n - 1) {
            max = (max > k - abs(a[n - 1] - a[0])) ? max
                                                   : k - abs(a[n - 1] - a[0]);
        } else {
            max = (max > a[i + 1] - a[i]) ? max : a[i + 1] - a[i];
        }
    }
    cout << k - max << endl;
}