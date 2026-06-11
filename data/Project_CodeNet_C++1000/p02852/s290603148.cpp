#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <functional>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
using namespace std;
using llong = long long;

llong n, m;
string s;
stack<llong> ans;

int main() {
    cin >> n >> m;
    cin >> s;

    for (int i = 0; i < s.size(); i++) {
        int cnt = 0;
        while (s[i] == '1') {
            i++;
            cnt++;
        }

        if (cnt >= m) {
            cout << -1 << endl;
            return 0;
        }
    }

    for (int i = s.size() - 1; i > 0; i--) {
        llong c = m;
        while (i - c < 0 || s[i - c] == '1') {
            c--;
        }

        i -= c - 1;
        ans.push(c);
    }

    while (!ans.empty()) {
        cout << ans.top() << ' ';
        ans.pop();
    }

    return 0;
}
