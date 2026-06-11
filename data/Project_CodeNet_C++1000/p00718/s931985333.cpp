#include <bits/stdc++.h>
using namespace std;

int main () {

    map<char,int> op;
    map<int,char> re;
    op['m'] = 1000;
    op['c'] = 100;
    op['x'] = 10;
    op['i'] = 1;
    re[1000] = 'm';
    re[100] = 'c';
    re[10] = 'x';
    re[1] = 'i';
    int n;
    cin >> n;
    while (n--) {
        string s, t;
        cin >> s >> t;
        int ss = 0, tt = 0;

        for (int i = 0; i < s.size(); i++) {
            if ('2' <= s[i] && s[i] <= '9') {
                int c = s[i] - '0';
                i++;
                ss += c * op[s[i]];
            } else {
                ss += op[s[i]];
            }
        }

        for (int i = 0; i < t.size(); i++) {
            if ('2' <= t[i] && t[i] <= '9') {
                int c = t[i] - '0';
                i++;
                tt += c * op[t[i]];
            } else {
                tt += op[t[i]];
            }
        }

        ss += tt;
        int k = 1;
        string res;
        while (ss) {
            int c = ss % 10;
            ss /= 10;

            if (c == 1) {
                res = re[k] + res;
            } else if (c > 1) {
                res = re[k] + res;
                char tmp = '0' + c;
                res = tmp + res;
            }
            k *= 10;
        }

        cout << res << endl;
    }
}