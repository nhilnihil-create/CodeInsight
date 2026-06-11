#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const ll INF = 1LL << 60;

ll a, b, c;
int main() {
    cin >> a >> b >> c;

    ll tmp = c - a - b;
    if (tmp <= 0) {
        cout << "No" << endl;
        return 0;
    }

    if (4 * a * b < tmp * tmp) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}