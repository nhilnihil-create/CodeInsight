#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    map<string, int> m;
    int max_cnt = 1;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (m.find(s) == m.end())
            m[s] = 1;
        else
            max_cnt = max(max_cnt, ++m[s]);
    }

    for (const auto &e : m)
        if (e.second == max_cnt)
            cout << e.first << endl;
}