#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const long long INF = 1LL << 60;

int main() { 
    long double W, H;
    cin >> W >> H;
    ll x, y;
    cin >> x >> y;
    cout << fixed<< setprecision(9) <<W * H / 2 << " "<<((x + x == W) && (y + y == H)) << endl;
    return 0;
}