#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int n;
    cin >> n;
    map<string, int> m;
    rep(i,n) {
        string st;
        cin >> st;
        if (m.count(st)) m.at(st)++;
        else m[st] = 1;
    }
    int cnt = 0;
    for (auto x : m) {
        cnt = max(cnt, x.second);
    }
    vector<string> y;
    for (auto x : m) {
        if (x.second == cnt) y.push_back(x.first);
    }
    sort(y.begin(), y.end());
    for (string s : y) {
        cout << s << endl;
    }
    return 0;
}