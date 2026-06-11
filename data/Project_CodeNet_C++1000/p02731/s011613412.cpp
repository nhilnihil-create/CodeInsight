#include <bits/stdc++.h>
using namespace std;

void solve () {
    double l;
    cin >> l;
    double side = l/3;
    cout << fixed << setprecision(12);
    cout << side * side * side;

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
