#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ll h, w;
    cin >> h >> w;
    ll ans = ((h + 1) / 2) * ((w + 1) / 2) + (h / 2) * (w / 2);
    if (h == 1 || w == 1) ans = 1;
    cout << ans << "\n";
}
