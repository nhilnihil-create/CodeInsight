#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

    int n, m; cin >> n >> m;
    int sum = 0;
    for (int i = 0; i < m; i++) {
        int a; cin >> a;
        sum += a;
    }
    if (n < sum) cout << -1 << endl;
    else cout << n - sum << endl;
    return 0;
}