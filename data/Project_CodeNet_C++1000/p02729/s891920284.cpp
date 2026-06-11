#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;
using ll = long long;

int main() {
    int n, m;
    int ans = 0;
    cin >> n >> m;
    for (int i = 1; i < n; i++) {
        ans += i;
    }
    for (int i = 1; i < m; i++) {
        ans += i;
    }
    cout << ans << endl;
}