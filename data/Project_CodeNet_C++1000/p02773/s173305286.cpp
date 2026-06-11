#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    string s;
    map<string, int> count;
    int cmax = 0;
    for(int i = 0; i < n; ++i) {
        cin >> s;
        count[s]++;
        cmax = max(cmax, count[s]);
    }
    for(pair<string, int> p: count) {
        if(p.second == cmax) cout << p.first << "\n";
    }

    return 0;
}