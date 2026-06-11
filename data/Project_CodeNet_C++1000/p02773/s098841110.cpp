#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;

    map<string, int> dict;
    for (size_t i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (dict.count(s) == 0) dict.insert(make_pair(s, 1));
        else ++dict[s];
    }

    int m = 0;
    for (auto i = dict.begin(); i != dict.end(); i++) m = max(m, i->second);

    for (auto i = dict.begin(); i != dict.end(); i++){
        if (i->second == m) cout << i->first << endl;
    }

    return 0;
}
