#include<bits/stdc++.h>
using namespace std;


int main() {
    string s;
    cin >> s;

    int ans = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i]=='R') {
            int tmp = 0;
            for (int j = i; j < s.size() && s[j] == 'R'; j++) {
                tmp++;
            }
            ans = max(ans, tmp);
        }
    }

    cout << ans << endl;


    return 0;
}
