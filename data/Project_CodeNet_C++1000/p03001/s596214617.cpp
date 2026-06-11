#include <bits/stdc++.h>
using namespace std;
/* typedef */
typedef long long ll;
typedef pair<int, int> pii;
/* constant */
const int INF = 1 << 30;
const ll LINF = 1LL << 50;
const int NIL = -1;
const int MAX = 10000;
const int mod = 1000000007;
const double pi = 3.141592653589;
/* global variables */
/* function */
/* main */
int main(){
    double W, H, x, y;
    cin >> W >> H >> x >> y;
    double ans = W * H / 2.0;
    int twoRectangle = (W/2.0 == x) && (H/2.0 == y);
    cout << fixed << setprecision(9) << ans << ' ' ;
    cout << twoRectangle << '\n';
}
