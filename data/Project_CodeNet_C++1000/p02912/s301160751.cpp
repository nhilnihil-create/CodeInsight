#include <algorithm>
#include <complex>
#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <queue>
#include <regex>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <thread>
#include <tuple>
#include <type_traits>
#include <vector>

#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    int n, m, a;
    cin >> n >> m;

    priority_queue<int> q;
    for (int i = 0; i < n; i++) {
        cin >> a;
        q.push(a);
    }

    for (int i = 0; i < m; i++) {
        a = q.top();
        q.pop();
        q.push(a / 2);
    }
    ll sum = 0;
    while (!q.empty()) {
        a = q.top();
        q.pop();
        sum += a;
    }

    cout << sum << endl;

    return 0;
}
