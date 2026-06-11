#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    map<string,int> s;
    string str;
    int max_cnt = 0, s_size = 0;
    for (int i = 0; i < n; i++) {
        cin >> str;
        if (s.find(str) == s.end()) {
            s[str] = 0;
            s_size++;
        } else {
            s[str]++;
        }
        if (s[str] > max_cnt) max_cnt = s[str];
    }

    for (auto it = s.begin(); it != s.end(); it++) {
        if (it->second == max_cnt) cout << it->first << endl;
    }

    return 0;
}
