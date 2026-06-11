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
    int n, a[200005] = {}, b[200005] = {};
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i] >> b[i];
    sort(a, a + n); sort(b, b + n);
    if (n % 2) cout << b[n / 2] - a[n / 2] + 1;
    else cout << b[n / 2] + b[n / 2 - 1] - a[n / 2] - a[n / 2 - 1] + 1;
}
