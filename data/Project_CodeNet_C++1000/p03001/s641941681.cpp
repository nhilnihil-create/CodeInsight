#include<bits/stdc++.h>
using namespace std;

#define LL long long

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    double w, h, x, y; cin >> w >> h >> x >> y;
    cout << fixed << setprecision(12) << (w * h) / 2.0 << " " << (x == w/2 && y == h/2);    
}