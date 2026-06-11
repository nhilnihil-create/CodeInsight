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

int main() {
    ios::sync_with_stdio(false);
    ll n, z = 1ll * mod * mod;
    cin >> n;
    for (ll i = 1; i * i <= n; i++) if (n % i == 0) z = min(z, i + n / i - 2);
    cout << z;
}
