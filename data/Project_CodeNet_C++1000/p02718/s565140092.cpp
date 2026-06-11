#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

    int n, m; cin >> n >> m;
    int sum = 0;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (4 * m * a[i] < sum) continue;
        cnt++;
    }
    if (m <= cnt) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}