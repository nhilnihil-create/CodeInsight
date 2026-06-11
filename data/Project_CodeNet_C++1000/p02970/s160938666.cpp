#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int, int> ii;

struct fastio {
    fastio() {
        ios::sync_with_stdio(false);
        cout << setprecision(10) << fixed;
        cin.tie(0);
    }
};

fastio _fast_io;

int n, d;

int main() {
    cin >> n >> d;
    d = d * 2 + 1;
    int res = n / d + (n % d ? 1 : 0);
    cout << res << endl;
    return 0;
}
