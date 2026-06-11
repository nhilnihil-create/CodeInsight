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
    int n, m = 7;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        if (m % n == 0) {
            cout << i;
            return 0;
        }
        m = (m * 10 + 7) % n;
    }
    cout << -1;
}
