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
    int n, z = 0;
    ll d, x, y;
    cin >> n >> d;
    while (n--) {
        cin >> x >> y;
        if (x * x + y * y <= d * d) z++;
    }
    cout << z;
}
