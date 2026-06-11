#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using p = pair<int, int>;
#define INF 1001001001
#define PI 3.14159265359
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define repX(i, n , x) for (int i = (int)(x); i < (int)(n); ++i)
#define repB(i, n) for (int i = n; i >= 1; --i)
#define repBX(i, n , x) for (int i = (int)(n); i >= int(X); --i)
#define dup(x,y) (((x)+(y)-1)/(y))

int main() {
    int X;
    cin >> X;
    int gohyaku = X/500;
    X %= 500;
    int ans = gohyaku*1000 + X - X%5;
    cout << ans << endl;
    
    return 0;
}