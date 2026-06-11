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
    ll n, m, z = 0;
    cin >> n >> m;
    for (ll i = m; i <= n + 1; i++) {
        //[0,i-1]~[n-i+1,n]
        z = (z + (n + n - i + 1) * i / 2 - (0 + i - 1) * i / 2 + 1) % mod;
    }
    cout << z;
}
