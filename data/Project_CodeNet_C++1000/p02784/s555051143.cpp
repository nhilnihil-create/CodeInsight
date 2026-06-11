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
    int h, n, a, b = 0;
    cin >> h >> n;
    while (n--) cin >> a, b += a;
    if (b >= h) cout << "Yes";
    else cout << "No";
}
