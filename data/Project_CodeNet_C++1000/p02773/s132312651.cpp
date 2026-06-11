#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define repr(i, n) for (int i = n-1; i >= 0; i--)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using pii = pair<int, int>;
const int mod = 1e9+7;
const int INF = 1e9;
const int MAX = 1e6;

template<class T> inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

int main() {
    // input
    int n;
    cin >> n;
    // solve
    map<string, int> dic;
    int max_c = 0;
    set<string> ans;
    rep(i, n) {
        string s;
        cin >> s;
        dic[s]++;
        if (chmax(max_c, dic[s])) {
            ans.clear();
            ans.insert(s);
        } else if (dic[s] == max_c) {
            ans.insert(s);
        }
    }
    // output
    for (string s : ans) {
        cout << s << endl;
    }
}