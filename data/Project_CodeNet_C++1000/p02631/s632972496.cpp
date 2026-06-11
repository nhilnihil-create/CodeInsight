#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)



int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) {
        cin >> a[i];
    }
    
    int all = 0;
    rep(i,n) {
        //all = all ^ a[i];
        all ^= a[i];
    }
    
    rep(i,n) {
        int ans = all ^ a[i];
        if(i == n-1)
            cout << ans << endl;
        else
            cout << ans << " ";
    }

    
    return 0;
}
