#include<bits/stdc++.h>

#define ntest 0

using namespace std;
string ans[10];
int n;
void solve() {
    ans[2] = ans[4] = ans[5] = ans[7] = ans[9] = "hon";
    ans[0] = ans[1] = ans[6] = ans[8] = "pon";
    ans[3] = "bon";
    cin >> n;
    cout << ans[n%10];
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


