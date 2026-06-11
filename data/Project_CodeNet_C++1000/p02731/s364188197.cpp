// Sky's the limit :)
#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int T = 1; 
    // cin >> T; 
    while (T--) {
        double n;
        cin >> n;

        n /= 3;
        n = n * n * n;
        cout << fixed << setprecision(7) << n << '\n'; 

    }
    
    return 0;
}

