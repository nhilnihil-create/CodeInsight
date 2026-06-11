#include <bits/stdc++.h>
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define REP(i, n) for(int i = 0; i < n; i++)
using namespace std;

int main() {
    string tmp, str;
    while (cin >> tmp) str += tmp;
    FOR(i, 'a', 'z'+1) {
        int s = 0;
        REP(j, str.size()) if (tolower(str[j]) == i) s++;
        cout << (char)i << " : " << s << endl;}
}