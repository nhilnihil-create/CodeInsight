#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define debug(x) cerr << "[(" << __LINE__ << ") " << (#x) << "]: " << x << endl;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    map<int, int> m;
    ll ans = 0;

    int n;
    cin >> n;
    
    //j-i = x+y
    //-i-x = -j+y
    for (int i=0; i<n; i++) {
        int x;
        cin >> x;
        ans += m[-i+x];
        m[-i-x]++;
    }
    cout << ans << "\n";
}
