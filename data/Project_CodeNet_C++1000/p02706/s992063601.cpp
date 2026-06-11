#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    long long sum = 0;
    int tmp;
    for (int i = 0; i < m; i++) {
        cin >> tmp;
        sum += tmp;
    }

    if (sum > n) {
        cout << -1 << endl;
    } else {
        cout << n - sum << endl;
    }
    
    return 0;
}
