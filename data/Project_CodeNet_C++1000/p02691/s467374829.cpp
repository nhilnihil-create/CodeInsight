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
    
    map<int,int> m;
    
    long int ans = 0;
    rep(i,n) {
        ans += m[i-a[i]];
        m[i+a[i]]++;
    }
    
    cout << ans << endl;
    
    return 0;
}
