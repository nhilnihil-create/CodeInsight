#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); ++i)
double const PI = 3.1415926535897932384626433;

int main() {
    ll a, b, n, ans = 0, rem;
    cin >> n >> a >> b;
    ans = n / (a + b) * a;
    rem = n % (a + b);
    ans += min(rem, a);
    cout << ans << endl;
    return 0;
}