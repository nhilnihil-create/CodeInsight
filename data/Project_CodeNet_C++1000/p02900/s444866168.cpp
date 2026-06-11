#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 1e18;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; i >= a; i--)
#define int ll
using pint = pair<int, int>;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

signed main() {
    int a, b;
    cin >> a >> b;
    int sum = gcd(a, b);
    map<int, int> mp;
    for (int i = 2; i * i <= sum; i++) {
        while (sum % i == 0) {
            mp[i]++;
            sum /= i;
        }
    }
    if (sum != 1) mp[sum]++;
    cout << mp.size() + 1 << "\n";
}