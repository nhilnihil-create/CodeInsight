#include<bits/stdc++.h>

#define ntest 0

using namespace std;
int n;
long long res;
void solve() {
    cin >> n;
    for (int i = 1; i < n; ++i) res += (n-1)/i;
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


