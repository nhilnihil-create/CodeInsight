#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <fstream>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int mod = 1000000007;

ll sol(ll n) {
    if (n == 1) return 1;
    return sol(n / 2) * 2 + 1;
}

int main() {
    ios::sync_with_stdio(false);
    int n, k;
    ll a[200005] = {}, z = 0;
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n); reverse(a, a + n);
    for (int i = k; i < n; i++) z += a[i];
    cout << z;
}
