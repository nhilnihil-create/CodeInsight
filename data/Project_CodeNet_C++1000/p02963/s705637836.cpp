#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <cstring>
#include <queue>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;

int main() {
    ll s;
    cin >> s;
    if (s > 1e9) {
        ll x1 = 1000000000, x2 = 1;
        ll y2 = (s + x1 - 1) / x1;
        ll y1 = x1 * y2 - s;
        cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << " 0 0";
    } else {
        cout << "0 " << s << " 1 0 0 0";
    }
}
