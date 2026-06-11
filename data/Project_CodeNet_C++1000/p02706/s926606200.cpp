#include <bits/stdc++.h>
using namespace std;
#define fastIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
typedef long long ll;

int main() {
    fastIO;
    int n, m;
    cin >> n >> m;
    int sum = 0;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        sum += x;
    }
    if (n >= sum) {
        cout << n - sum;
    }
    else {
        cout << -1;
    }
}