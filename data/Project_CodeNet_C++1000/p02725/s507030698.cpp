#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)



int main() {
    int k, n;
    cin >> k >> n;
    vector<int> a(n);
    rep(i,n) {
        cin >> a[i];
    }
    
    sort(a.begin(), a.end());
    
    int ans = k;
    rep(i,n) {
        int d;
        if(i == 0) {
            d = a.back() - a[i];
        }
        else {
            d = a[i] - a[i-1];
        }
        ans = min(ans, max(d, k-d));
    }
    
    cout << ans << endl;
    
    return 0;
}


