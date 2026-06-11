#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define debug(x) cerr << "[(" << __LINE__ << ") " << (#x) << "]: " << x << endl;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int l, r, d;
    cin >> l >> r >> d;

    cout << r/d - (l+d-1)/d + 1 << "\n";
}
