#include <bits/stdc++.h>

using namespace std;


int main() {
    string s;
    cin >> s;
    int ans = 0;
    string cur = "", p = "";
    for(int i = 0; i < s.size(); i++) {
        cur += s[i];
        if(cur != p) {
            ans++;
            p = cur;
            cur = "";
        }
    }
    cout << ans << "\n";
    return 0;
}