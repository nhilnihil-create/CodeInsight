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
    
    vector<double> a(n);
    double c = 1;
    rep(i,n) {
        cin >> a[i];
        c *= a[i];
    }
    
    double p = 0;
    rep(i,n) {
        p += c / a[i];
    }
    
    cout << fixed << setprecision(7) << c / p << endl;
    
    
    
    return 0;
}
