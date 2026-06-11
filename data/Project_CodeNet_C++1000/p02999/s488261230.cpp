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
    int x; cin >> x;
    int a; cin >> a;

    if (x < a) cout << 0 << endl;
    else cout << 10 << endl;
    return 0;
}
