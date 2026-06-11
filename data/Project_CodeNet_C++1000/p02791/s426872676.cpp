#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n;
    cin >> n;
    vector<int> p(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> p.at(i);
    }
    int ans = 1;
    int mi = p.at(1);
    for (int i = 2; i <= n; i++) {
        if (mi > p.at(i)) {
            ans++;
            mi = p.at(i);
        }
    }
    cout << ans << endl;
    return 0;
}
