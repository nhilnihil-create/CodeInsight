#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    ll w, h, x, y;
    cin >> w >> h >> x >> y;
    
    printf("%.15f ",(double)(w) * (double)(h) / (double)(2));
    if (w % 2 == 0 && h % 2 == 0 && x == w / 2 && y == h / 2) cout << 1;
    else cout << 0;
}
