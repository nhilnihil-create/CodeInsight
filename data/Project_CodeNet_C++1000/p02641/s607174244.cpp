#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;
// MAX int 2,147,483,647 -> 10桁
// MAX ll 9,223,372,036,854,775,807 -> 19桁
// MAX O(n) 10^18 -> 18回

int main() {
    int X, N;
    cin >> X >> N;
    vector<int> p(N);
    rep(i, N) cin >> p.at(i);  // 0-index

    int ans;
    int larger = X;
    int smaller = X;
    bool found;
    while (larger != 1000 && smaller != -1000) {
        
        found = false;
        rep(i, N) {
            if (smaller == p.at(i)) found = true;
        }
        if (!found) {
            ans = smaller;
            break;
        }
        smaller--;

        found = false;
        rep(i, N) {
            if (larger == p.at(i)) found = true;
        }
        if (!found) {
            ans = larger;
            break;
        }
        larger++;
    }

    cout << ans << endl;

    return 0;
}
