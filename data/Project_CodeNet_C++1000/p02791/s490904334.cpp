#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
using ll = long long;

int main() {
    int n;
    cin >> n;
    
    int p;
    int m = INT_MAX;
    int ans = 0;
    rep(i,n) {
        cin >> p;
        if (p <= m) {
            m = p;
            ans++;
        }
    }

    cout << ans << endl;
    
    return 0;
}