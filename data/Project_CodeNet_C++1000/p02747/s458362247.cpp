#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    string s; cin >> s;
    bool h_flg = false;
    bool ans = false;
    rep(i, s.size()) {
        if (i % 2 == 0 && s[i] == 'h') {
            ans = false;
        }
        else if (i %2 == 1 && s[i] == 'i') {
            ans = true;
        }
        else {
            puts("No");
            return 0;
        }
    }
    if (ans) puts("Yes");
    else  puts("No");
#if 0
    if (s.find("hi") != string::npos) {
        puts("Yes");
    }
    else puts("No");
#endif
}
