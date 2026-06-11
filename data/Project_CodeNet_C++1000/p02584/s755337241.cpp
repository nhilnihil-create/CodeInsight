#include<bits/stdc++.h>

#define ntest 0

using namespace std;
long long x,k,d;
void solve() {
    cin >> x >> k >> d;
    x = abs(x);
    if (x / d >= k) {
        cout << x - k * d;
        return;
    }
    long long tmpk = x / d;
    long long remain = k - tmpk;
    if (remain&1) cout << abs(x-(tmpk+1)*d);
    else cout << x - tmpk * d;
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


