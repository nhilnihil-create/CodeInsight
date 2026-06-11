#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define REP(i, n) for(long long i = 0; i < (long long)(n); i++)
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
int main(){
    double a, b, x;
    cin >> a >> b >> x;
    double r;
    if(x <= a * a * b / 2){
        r = atan2(b * b, 2 * (x / a));
    }
    else{
        r = atan2(2 * (a * b - (x / a)), a * a);
    }
    double ans = r / (2 * acos(-1)) * 360;
    cout << fixed << setprecision(12) << ans << endl;
}