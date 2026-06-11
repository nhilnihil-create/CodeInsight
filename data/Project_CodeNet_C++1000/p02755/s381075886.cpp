#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)



int main() {
    int a, b;
    cin >> a >> b;
    
    int ans = -1;
    
    rep(i,1300) {
        if(i * 8 / 100 == a && i * 10 / 100 == b) {
            ans = i;
            break;
        }
    }
    
    cout << ans << endl;
    
    return 0;
}


