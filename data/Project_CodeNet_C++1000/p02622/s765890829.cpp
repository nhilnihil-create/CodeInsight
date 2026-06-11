#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    string s, t;
    int cnt = 0;
    cin >> s >> t;
    for (int i = 0; i < s.size(); ++i) {
        if(s[i] != t[i]) {
            cnt++;
        }
    }
    cout << cnt << endl;

}
