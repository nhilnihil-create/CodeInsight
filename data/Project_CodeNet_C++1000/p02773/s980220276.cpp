#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int n;
    cin >> n;
    map<string, int> m;
    string s;
    int maxx = -1;
    int tmp;
    rep(i, n){
        cin >> s;
        if (!(m.count(s))) {
            m.insert(make_pair(s, 1));
        } else {
            ++m[s];
        }
        maxx = max(maxx, m[s]);
    }

    for (auto x : m) {
        if (x.second == maxx) {
            cout << x.first << endl;
        }
    }
    
    return 0;
}