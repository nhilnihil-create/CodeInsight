#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 1001001001;

int main() {
    int k;
    cin >> k;
    int ans = -1;
    int n = 7 % k;
    for (int i = 0; i < k; ++i) {
        if (n == 0) {
            ans = i + 1;
            break;
        }
        n = (n * 10 + 7) % k;
    }
    cout << ans << endl;
}