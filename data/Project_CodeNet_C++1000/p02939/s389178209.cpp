#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    string s;
    cin >> s;
    queue<char> q;
    rep(i,s.size()) q.push(s[i]);
    string pre = "*";
    int ans = 0;
    while (!q.empty()) {
        string t;
        t.push_back(q.front());
        q.pop();
        if (t == pre && !q.empty()) {
            t.push_back(q.front());
            q.pop();
        }
        if (t == pre && q.empty()) ans--;
        pre = t;
        ans++;
    }
    cout << ans << endl;
}