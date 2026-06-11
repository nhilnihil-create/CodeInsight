#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> s(n);
    vector<int> t(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i] >> t[i];
    }
    
    string u;
    cin >> u;
    
    int ans = 0;
    bool flag = false;
    for (int i = 0; i < n; i++) {
        if (flag) ans += t[i];
        flag |= (s[i] == u);
    }
    
    cout << ans << endl;
    return 0;
}