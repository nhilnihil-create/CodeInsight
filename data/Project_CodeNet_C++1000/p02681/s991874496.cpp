#include <bits/stdc++.h>

//#define int long long

using namespace std;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    bool flag = false;
    string a, b;
    cin >> a >> b;
    if (b.length() != a.length()+1) {
        cout << "No\n";
        exit(0);
    }
    for (int i = 0; i < a.length(); i++) if (a[i] != b[i]) flag = true;
    if (flag) cout << "No\n";
    else cout << "Yes\n";
}
/*

 */