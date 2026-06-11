#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    int ans = 1, ss = s.size();
    string a, b;
    a = s[0];
    for (int i = 1; i < ss; i++) {
        b = s[i];
        if (a == b && i == ss-1)
            break;
        else if (a == b) {
            i++;
            b += s[i];
        }
        ans++;
        a = b;
    }
    cout << ans << endl;
}