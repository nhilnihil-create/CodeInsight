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
int x, a;

int main() {
    cin >> x >> a;
    if (x < a)
        cout << 0 << endl;
    else
        cout << 10 << endl;
    return 0;
}
