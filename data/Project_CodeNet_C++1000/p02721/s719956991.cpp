#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;
typedef long long ll;
ll n, k, c, lst;
bool flag;
string s;
ll cnt;
bool vis[200010];
stack<int> stk;
int main() {
    cin >> n >> k >> c;
    cin >> s;
    lst = -1;
    for (int i = 0; i < (int)(s.length()); i++) {
        if (s[i] == 'x' || lst >= i) continue;
        if (cnt >= k) {
            flag = 1;
            break;
        }
        lst = i + c;
        vis[i] = 1;
        cnt++;
    }
    if (flag) {
        return 0;
    }
    lst = s.length();
    for (int i = (int)s.length() - 1; i >= 0; i--) {
        if (s[i] == 'x' || lst <= i) continue;
        lst = i - c;
        if (vis[i]) {
            stk.push(i);
        }
    }
    while (!stk.empty()) {
        cout << stk.top() + 1 << endl;;
        stk.pop();
    }
    return 0;
} 