#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> s(m), c(m);
    for (int i = 0; i < m; i++) cin >> s[i] >> c[i];
    
    int l;
    if (n == 1) l = 0;
    else if (n == 2) l = 10;
    else l = 100;

    for (int i = l; i < 1000; i++) {
        string t = to_string(i);
        t += "  ";
        bool f = true;
        for (int j = 0; j < m; j++) {
            if (t[s[j]-1] != ('0' + c[j])) {
                f = false;
                break;
            }
        }
        if (f) {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}