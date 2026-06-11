#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;

int main() {
    int k, x;
    cin >> k >> x;
    for (int i = -k + 1; i < k; i++) {
        cout << x + i;
        if (i == k - 1) {
            cout << endl;
        } else {
            cout << " ";
        }
    }
    return 0;
}