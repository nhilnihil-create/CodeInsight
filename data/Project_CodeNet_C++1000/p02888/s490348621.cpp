#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
 
int n, ans;
vector <int> l;
int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ans = 0;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        int x; cin >> x;
        l.pb(x);
    }
    sort(all(l));
    for(int i = n-1; i >= 2; --i) {
        for(int j = i-1; j >= 1; --j) {
            auto a = upper_bound(all(l), l[i]-l[j]);
            auto b = l.begin() + j - 1;
            if (b - a >= 0) ans += (b - a + 1);
        }
    }
    cout << ans;
}
