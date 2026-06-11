#include <bits/stdc++.h>
using namespace std;
int main (void) {
    int n; cin >> n;
    int ans = (n&1) ? n/2 : n/2-1;
    cout << ans << "\n";
    return 0;
}
