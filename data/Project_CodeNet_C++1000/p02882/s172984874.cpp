#include <bits/stdc++.h>
//#include <atcoder/all>
//using namespace atcoder;
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)
typedef pair<int,int> P;
typedef long long ll;



int main() {
    double a, b, x;
    cin >> a >> b >> x;
    
    double ans;
    if(x >= a*a*b/2) {
        double h = (a*a*b - x) * 2 / (a*a);
        ans = atan(h/a);
        ans = ans * 180.0 / M_PI;
    }
    else {
        double h = x * 2 / (a*b);
        ans = atan(h/b);
        ans = 90 - ans * 180.0 / M_PI;
    }
    
    cout << fixed << setprecision(8) << ans << endl;
    
    
    
    return 0;
}


