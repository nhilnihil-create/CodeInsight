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
    int x, n, a[102] = {}, b, y = 328, z = 0;
    cin >> x >> n;
    for (int i = 0; i < n; i++) cin >> b, a[b] = 1;
    for (int i = 0; i < 102; i++) {
        if (!a[i]) {
            if (abs(x - i) < y) y = abs(x - i), z = i;
        }
    }
    cout << z;
}
