#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;
using ll = long long;

int main() {
    ll a, b, k;
    cin >> a >> b >> k;
    if (a + b < k) {
        a = 0;
        b = 0;
    }
    else if (a < k) {
        k -= a;
        a = 0;
        b -= k;
    }
    else {
        a -= k;
    }
    cout << a << " " << b << endl;
}