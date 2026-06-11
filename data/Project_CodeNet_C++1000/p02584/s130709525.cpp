#include<bits/stdc++.h>

#define ntest 0

using namespace std;
long long x,k,d;
void solve() {
    cin >> x >> k >> d;
    x = abs(x);
    long long tmpk = min(k,x / d);
    long long remain = k - tmpk;
    if (remain&1) cout << (tmpk+1)*d - x;
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


