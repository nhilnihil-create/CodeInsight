#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; i++) cin >> s[i];

    sort (s.begin(), s.end());
    vector<pair<int,string>> v = {{1, s[0]}};
    int c = 0;
    for (int i = 1; i < n; i++) {
        if (s[i] == v[c].second) v[c].first++;
        else {
            v.push_back({1, s[i]});
            c++;
        }
    }
    sort (v.begin(), v.end());
    int m = v[c].first;
    for (int i = 0; i <= c; i++) {
        if (v[i].first == m) cout << v[i].second << endl;
    }
}