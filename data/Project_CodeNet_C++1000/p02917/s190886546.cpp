#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;

int main() {
    int n;
    cin >> n;
    vector<int> b(n - 1);
    for (int i = 0; i < n - 1; i++) {
        cin >> b[i];
    }
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            sum += b[i];
        } else if (i == n - 1) {
            sum += b[i - 1];
        } else {
            sum += min(b[i - 1], b[i]);
        }
    }
    cout << sum << endl;
    return 0;
}