#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main() {
        string s;
        string b;
        int cnt = 0;

        cin >> s;
        cin >> b;
        rep(i, s.size()) {
                if(s[i] != b[i]) {
                        cnt++;
                }
        }
        cout << cnt << endl;
        return 0;
}