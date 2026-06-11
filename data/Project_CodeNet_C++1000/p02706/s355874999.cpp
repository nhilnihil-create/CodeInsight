#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
    int n, m;
    cin >> n >> m;

    int days = 0;
    for (size_t i = 0; i < m; i++) {
        int a;
        cin >> a;
        days += a;
    }

    if (days > n) cout << -1 << endl;
    else cout << n - days << endl;
    return 0;
}
