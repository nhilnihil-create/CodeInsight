#include<bits/stdc++.h>

#define ntest 0
#define PI acos(-1)

using namespace std;
int a, b, h, m;
double ah, am, angle;
void solve() {
    cin >> a >> b >> h >> m;
    ah = h * 30;
    am = m * 6;
    ah += m * 0.5;
    angle = abs(ah - am);
    if (angle > 180) angle = 360 - angle;
    cout << fixed << setprecision(20) << sqrt(a *1.0* a + b * b - 2 * a * b * cos(angle*PI/180.0));
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    if(ntest){
        int t;
        cin >> t;
        while(t--) solve();
    } else {
        solve();
    }

}


