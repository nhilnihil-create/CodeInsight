#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int ans = 0;
    int cur = 0;
    for(char& c : s) {
        if(c == 'R') {
            cur++;
        } else {
            ans = max(ans, cur);
            cur = 0;
        }
    }
    ans = max(ans, cur);
    cout << ans;
}