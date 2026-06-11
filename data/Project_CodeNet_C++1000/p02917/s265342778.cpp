#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
/////////////////////////////////
int main(){
    int n;
    cin >> n;
    vector<int> a(n,0),b(n-1);
    rep(i, n-1) cin >> b[i];
    a[0] = b[0];
    a[n - 1] = b[n - 2];
    for (int i = 1; i < n - 1;i++)
            a[i] = min(b[i - 1], b[i]);
    int ans = 0;
    rep(i, n) ans += a[i];
    cout << ans << endl;
}