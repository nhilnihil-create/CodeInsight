#include <bits/stdc++.h>
//#include <atcoder/all>
//using namespace atcoder;
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)
typedef pair<int,int> P;
typedef long long ll;



int main() {
    int n;
    cin >> n;
    
    ll xd0, yd0, xd1, yd1;
    xd0 = yd0 = 100100100100;
    xd1 = yd1 = -100100100100;
    rep(i,n) {
        ll x, y;
        cin >> x >> y;
        
        xd0 = min(xd0, x-y);
        yd0 = min(yd0, x+y);
        xd1 = max(xd1, x-y);
        yd1 = max(yd1, x+y);
    }
    
    cout << max(xd1 - xd0, yd1- yd0) << endl;
    
    
    return 0;
}
