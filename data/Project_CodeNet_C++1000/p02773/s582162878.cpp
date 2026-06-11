#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

int main() {
    int n;
    cin >> n;
    map<string, int> m;
    pair<int, string> p;
    vector<pair<int, string>> v;
    rep(i, n) {
        string tmp;
        cin >> tmp;
        if(m.find(tmp) == m.end())
            m[tmp] = 1;
        else {
            m[tmp] += 1;
        }
    }
    int maxv = 0;
    for(const auto &x : m) {
        int v = x.second;
        if(v > maxv)
            maxv = v;
    }

    for(auto it = m.begin(); it != m.end(); it++) {
        if(it->second == maxv) {
            cout << it->first << endl;
        }
    }
    return 0;
}
