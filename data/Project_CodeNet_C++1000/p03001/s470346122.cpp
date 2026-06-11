#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define rep(i,n) for (int i = 0; i < n; i++)

int main() {
    ll w,h,x,y;
    cin >> w >> h >> x >> y;
    double ans = (double) (h*w) / 2;
    int b = 0;
    if (w%2 == 0 && h%2 == 0 && w/2 == x && h/2 == y) b++;
    cout << ans << " " << b << endl;
    return 0;
}