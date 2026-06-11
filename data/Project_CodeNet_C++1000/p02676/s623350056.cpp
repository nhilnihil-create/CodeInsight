#include<bits/stdc++.h>

#define ntest 0

using namespace std;
int k;
string s;
void solve() {
    cin >> k >> s;
    if (s.size() <= k) cout << s;
    else cout << s.substr(0,k) << "...";
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


