#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;
    cout << (!a ? 1 : !b ? 2 : !c ? 3 : !d ? 4 : 5) << endl;
    return 0;
}
