#include<bits/stdc++.h>

#define ntest 0

using namespace std;
int x;
void solve() {
    cin >> x;
    cout << 1 - x;
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


