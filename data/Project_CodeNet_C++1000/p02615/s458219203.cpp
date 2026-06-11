#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> a;
ll sum;
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        a.push_back(x);
    }
    sort(a.begin(), a.end());
    if (n > 1) {
        sum += a[n - 1];
    }
    int k = n - 2;
    for (n = n - 2; n >= 2; k--, n -= 2) {
        sum += a[k] * 2;
    }
    if (n == 1) {
        sum += a[k];
    }
    cout << sum << endl;
    return 0;
}