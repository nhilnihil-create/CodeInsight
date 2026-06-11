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
    int n, k, a[1003] = {}, z = 0;
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    for (int i = 0; i < k; i++) z += a[i];
    cout << z;
}
