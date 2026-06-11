#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    vector<int> a(s.size()+1, 0);
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '<') a[i+1] = a[i] + 1;
    }
    for (int i = s.size()-1; i >= 0; i--) {
        if (s[i] == '>') a[i] = max (a[i], a[i+1]+1);
    }
    long long ans = 0;
    for (int i = 0; i <= s.size(); i++) ans += a[i];
    cout << ans << endl;
}
