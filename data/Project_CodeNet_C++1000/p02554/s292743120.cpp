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
    int n;
    ll a = 1, b = 1, c = 1;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        a = a * 10 % mod;
        b = b * 9 % mod;
        c = c * 8 % mod;
    }
    cout << (a - b - b + c + 4ll * mod) % mod;
}
