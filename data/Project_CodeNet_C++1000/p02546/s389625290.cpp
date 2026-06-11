#include<bits/stdc++.h>

#define ntest 0

using namespace std;
string s;
void solve() {
    cin >> s;
    s += (s.back() == 's'?"es":"s");
    cout << s;
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


