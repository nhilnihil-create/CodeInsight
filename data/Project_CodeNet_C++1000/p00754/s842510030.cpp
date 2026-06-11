#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;
using ll = long long;

#define all(c) (c).begin(), (c).end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define pb(e) push_back(e)
#define mp(a, b) make_pair(a, b)
#define fr first
#define sc second

const ll INF = 1e9;
const ll MOD = 1e9 + 7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool ok(char c) {
    if (c == '(') return true;
    if (c == ')') return true;
    if (c == '[') return true;
    if (c == ']') return true;
    return false;
}
string s;
void solve() {
    stack<char> st;
    bool ans = true;
    rep(i, s.size()) {
        if (!ok(s[i])) continue;
        if (s[i] == '(' || s[i] == '[') st.push(s[i]);
        if (s[i] == ')') {
            if (st.size() && st.top() == '(')
                st.pop();
            else
                ans = false;
        }
        if (s[i] == ']') {
            if (st.size() && st.top() == '[')
                st.pop();
            else
                ans = false;
        }
    }
    if (ans && st.empty())
        cout << "yes" << endl;
    else
        cout << "no" << endl;
}
int main() {
    while (getline(cin, s)) {
        if (s == ".") break;
        solve();
    }
    return 0;
}