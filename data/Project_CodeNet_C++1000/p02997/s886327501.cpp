#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    if (k > (n - 1) * (n - 2) / 2) cout << -1;
    else {
        k = (n - 1) * (n - 2) / 2 - k;
        cout << n - 1 + k << '\n';
        for (int i = 2; i <= n; i++) cout << 1 << ' ' << i << '\n';
        for (int i = 2; i <= n; i++) {
            for (int j = 2; j < i; j++) {
                cout << j << ' ' << i << '\n';
                k--;
                if (!k) break;
            }
            if (!k) break;
        }
    }
}
