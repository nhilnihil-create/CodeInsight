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
    int n, a[200005] = {};
    ll z = 0;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n); reverse(a, a + n);
    for (int i = 1; i < n; i++) z += a[i / 2];
    cout << z;
}
