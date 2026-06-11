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

int gcd(int a, int b) {
    while (b) {
        int c = a % b;
        a = b;
        b = c;
    }
    return a;
}

ll po(ll a, ll b) {
    ll c = 1;
    while (b) {
        if (b % 2) c = c * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return c;
}

int main() {
    ios::sync_with_stdio(false);
    int n, k;
    ll d[100005] = {}, z = 0;
    cin >> n >> k;
    for (int i = 1; i <= k; i++) d[i] = po(k / i, n);
    for (int i = k; i; i--) for (int j = i + i; j <= k; j += i) {
        d[i] -= d[j];
        if (d[i] < 0) d[i] += mod;
    }
    for (int i = 1; i <= k; i++) z = (z + d[i] * i) % mod;
    cout << z;
}
