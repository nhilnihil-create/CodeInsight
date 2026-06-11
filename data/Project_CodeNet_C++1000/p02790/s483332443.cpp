#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)



int main() {
    int a, b;
    cin >> a >> b;
    
    int mn = min(a,b);
    int mx = max(a,b);
    
    rep(i,mx) {
        cout << mn;
    }
    cout << endl;
    
    
    return 0;
}
