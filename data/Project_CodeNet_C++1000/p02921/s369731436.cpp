#include<iostream>
#include<algorithm>
#include<math.h>
#include<vector>
#include<map>
#include<set>

using namespace std;
using ll = long long;

const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;
const double PI = 4.0 * atan(1.0);

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rrep(i, a, n) for (int i = a; i <= (n); ++i)

int main() {
    string S; cin >> S;
    string T; cin >> T;

    int ans = 0;
    if (S[0] == T[0]) ans++;
    if (S[1] == T[1]) ans++;
    if (S[2] == T[2]) ans++;

    cout << ans << endl;
    return 0;
}
