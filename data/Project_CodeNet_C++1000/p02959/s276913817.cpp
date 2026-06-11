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
    
    vector<int> a(n+1), b(n);
    rep(i,n+1) cin >> a[i];
    rep(i,n) cin >> b[i];
    
    ll cnt = 0;
    rep(i,n) {
        if(a[i] >= b[i]) {
            a[i] -= b[i];
            cnt += b[i];
        }
        else {
            b[i] -= a[i];
            cnt += a[i];
            a[i] = 0;
            if(a[i+1] >= b[i]) {
                a[i+1] -= b[i];
                cnt += b[i];
            }
            else {
                cnt += a[i+1];
                a[i+1] = 0;
            }
        }
    }
    
    cout << cnt << endl;
    
    
    
    
    return 0;
}
