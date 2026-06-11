#include <algorithm>
#include <bitset>
#include <climits>
#include <complex>
#include <fstream>
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

#include <stdio.h>

using ll = long long;
using namespace std;

vector<vector<bool>> v;

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    int x, l;

    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   function<bool(const pair<int, int>, const pair<int, int>)>>
        q([](const pair<int, int>& l, const pair<int, int> r) {
            return l.second > r.second;
        });
    for (int i = 0; i < n; i++) {
        cin >> x >> l;
        q.emplace(x - l, x + l);
    }

    int last = INT_MIN;
    int ans = 0;
    while (!q.empty()) {
        pair<int, int> p = q.top();
        q.pop();
        if (p.first < last) {
            ans++;
            continue;
        }
        last = p.second;
    }
    cout << (n - ans) << endl;

    return 0;
}
