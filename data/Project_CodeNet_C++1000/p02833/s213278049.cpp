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
    cin >> n;
    if (n % 2) cout << 0;
    else {
        ll a = 5, z = 0;
        while (a < n) {
            ll b = n / a;
            z += b / 2;
            a *= 5;
        }
        cout << z;
    }
}
