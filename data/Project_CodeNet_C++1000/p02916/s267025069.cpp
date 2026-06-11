#include <iostream>
#include<vector>
#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = 1; i <= (n); i++)
using ll = long long;

using namespace std;



int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n);
    int ans = 0;
    rep(i,n) cin >> a[i];
    rep(i,n) {
        cin >> b[i];
        ans += b[i];
    }
    rrep(i,n-1) cin >> c[i];
    rep(i,n-1) {
        if(a[i+1]-a[i]==1) ans += c[a[i]];
    }
    cout << ans << endl;

    return 0;
}
