#include <bits/stdc++.h>
using namespace std;
 
#define int         long long
#define endl        "\n"
#define pii         pair<int, int>
 
 
void solve(int TC) { 
    int n; cin >> n;
    bool ok = 0;
    for(int i=1; i<=9; i++) for(int j=1; j<=9; j++) {
        if(i*j == n) {
            ok = 1;
        }
    }
    if(ok) {
        cout << "Yes";
    } else {
        cout << "No";
    }
}
 
signed main() {
 
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(12);
 
 
    int T = 1;
    //cin >> T;
    for(int i=1; i<=T; i++) {
        solve(i);
    }
    return 0;
 
}