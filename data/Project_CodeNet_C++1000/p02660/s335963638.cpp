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
    ll n, m;
    int z = 0;
    cin >> n; m = n;
    for (ll i = 2; i * i <= m; i++) {
        int c = 0;
        if (n % i == 0) {
            while (n % i == 0) n /= i, c++;
            for (int j = 1; j < 28; j++) {
                if (c >= j) c -= j, z++;
                else break;
            }
        }
    }
    if (n > 1) z++;
    cout << z;
}
