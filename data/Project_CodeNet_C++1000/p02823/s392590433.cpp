#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll n, a, b, ans;
    cin >> n >> a >> b;

    if ((b - a) % 2 == 0) ans = (b - a) / 2;
    else ans = (b - a - 1) / 2 + min(a, n - b + 1);
        
    cout << ans << endl;
    return 0;
}