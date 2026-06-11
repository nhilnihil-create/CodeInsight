#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)



int main() {
    vector<int> a(9);
    rep(i,9) {
        cin >> a[i];
    }
    
    int n;
    cin >> n;
    vector<int> b(n);
    rep(i,n) {
        cin >> b[i];
    }
    
    rep(i,9) {
        rep(j,n) {
            if(a[i] == b[j])
                a[i] = 0;
        }
    }
    
    bool tf = false;
    if((a[0] == 0 && a[1] == 0 && a[2] == 0) ||
       (a[3] == 0 && a[4] == 0 && a[5] == 0) ||
       (a[6] == 0 && a[7] == 0 && a[8] == 0) ||
       (a[0] == 0 && a[3] == 0 && a[6] == 0) ||
       (a[1] == 0 && a[4] == 0 && a[7] == 0) ||
       (a[2] == 0 && a[5] == 0 && a[8] == 0) ||
       (a[0] == 0 && a[4] == 0 && a[8] == 0) ||
       (a[2] == 0 && a[4] == 0 && a[6] == 0))
        tf = true;
    
    if(tf)
        cout << "Yes" ;
    else
        cout << "No" ;
    
    
    return 0;
}
