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
    ll n;
    int z = 0;
    cin >> n;
    for (ll i = 1; i * i <= n - 1; i++) if ((n - 1) % i == 0) {
        if (i > 1) z++;
        if (i * i != n - 1) z++;
    }
    for (ll i = 1; i * i <= n; i++) if (n % i == 0) {
        if (i > 1) {
            ll j = n;
            while (j % i == 0) j /= i;
            if (j % i == 1) z++;
        }
        if (i * i != n) {
            ll j = n;
            while (j % (n / i) == 0) j /= (n / i);
            if (j % (n / i) == 1) z++;
        }
    }
    cout << z;
}
