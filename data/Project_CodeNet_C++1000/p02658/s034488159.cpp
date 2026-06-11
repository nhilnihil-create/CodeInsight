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
    ll a[100005] = {}, b = 1;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) if (!a[i]) {
        cout << 0;
        return 0;
    }
    for (int i = 0; i < n; i++) {
        if (b > 1000000ll * 1000000ll * 1000000ll / a[i]) {
            cout << -1;
            return 0;
        }
        b *= a[i];
    }
    cout << b;
}
