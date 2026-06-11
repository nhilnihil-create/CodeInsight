#include <bits/stdc++.h>

using namespace std;

#define lli long long
#define ld long double
#define mod 1000000007 
#define set(n) cout << fixed << setprecision(n)    
#define fi first
#define se second
#define mp make_pair
#define pll pair<lli, lli>
#define endl '\n'

const double PI = acos(-1);
const double epsilon = 1e-7;  // floating point precision

signed main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int k;
    cin >> k;
    vector<bool> seen(k);
    int md = 0;
    int pos = 0;
    while(true) {
        md = (md * 10 + 7) % k;
        pos ++;
        if(md == 0) {
            cout << pos << endl; 
            break;
        }
        if(seen[md]) {
            cout << -1 << endl;
            break;
        }
        seen[md] = true;
    }
    return 0;
}
 