#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;

int main() {
    int h, n;
    cin >> h >> n;
    int *a = new int[n];
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    string ans = "Yes";
    if (sum < h) {
        ans = "No";
    }
    cout << ans << endl;
    return 0;
}