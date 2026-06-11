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
const double PI = acos(-1.0);

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rrep(i, a, n) for (int i = a; i <= (n); ++i)

int main() {
    char c[10];
    cin >> c;

    if ((c[0] == c[1] && c[0] != c[2] && c[2] == c[3])
    || (c[0] == c[2] && c[0] != c[3] && c[1] == c[3])
    || (c[0] == c[3] && c[0] != c[1] && c[1] == c[2])) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
