#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 998244353;

int main() {
    ll S;
    cin >> S;
    ll x1, x2, x3, y1, y2, y3;
    x1 = 0;
    y1 = 0;
    x2 = 1000000000;
    y2 = 1;
    x3 = (x2-S%x2)%x2;
    y3 = (S+x3)/x2;

    printf("%ld %ld %ld %ld %ld %ld\n", x1, y1, x2, y2, x3, y3);
}
