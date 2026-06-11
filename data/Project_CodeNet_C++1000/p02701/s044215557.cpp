#include <bits/stdc++.h>
using namespace std;

void solve () {
    int n;
    cin >> n;
    set<string> s;
    for (int i = 0; i < n; i++) {
        string x;
        cin >> x;
        s.insert(x);
    }
    cout << s.size();

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
