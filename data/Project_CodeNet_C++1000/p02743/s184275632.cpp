#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int main() {
    ll a, b, c;
    cin >> a >> b >> c;
    ll x = c - a - b;
    cout << ((4 * a * b < x * x && x > 0) ? "Yes" : "No") << endl;
    return 0;
}