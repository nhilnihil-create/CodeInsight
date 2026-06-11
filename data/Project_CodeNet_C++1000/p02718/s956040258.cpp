#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;

int main() {
    int n, m;
    cin >> n >> m;
    int *a = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] * 4 * m >= sum) {
            cnt++;
        }
    }
    if (cnt >= m) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}