#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ll a, b, c;
    cin >> a >> b >> c;
    ll d = c - a - b;
    bool ans = 1;
    if (d <= 0) ans = 0;
    ll l = 4 * a * b;
    if (l >= d * d) ans = 0;
    if (ans) puts("Yes");
    else puts("No");
}
