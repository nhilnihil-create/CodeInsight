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
    
    vector<double> v(n);
    rep(i,n) {
        cin >> v[i];
    }
    
    sort(v.begin(),v.end());
    
    double ans = v[0];
    for(int i = 1; i < n; i++) {
        ans = (ans + v[i]) / 2;
    }
    
    cout << ans << endl;
    
    
    return 0;
}
