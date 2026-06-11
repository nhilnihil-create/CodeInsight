#include<bits/stdc++.h>

#define ntest 0

using namespace std;
int n;
int a[105];
long long res;
int ok(int x, int y, int z) {
    return (x + y > z && x + z > y && y + z > x);
}
int cal(int x, int y, int z) {
    return (x != z && x != y && y != z);
}
void solve() {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n - 2; ++i)
        for (int j = i + 1; j <= n - 1; ++j)
        for (int k = j + 1; k <= n; ++k) if (ok(a[i],a[j], a[k])) res += cal(a[i], a[j], a[k]);
    cout << res;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    if(ntest){
        int t;
        cin >> t;
        while(t--) solve();
    } else {
        solve();
    }

}


