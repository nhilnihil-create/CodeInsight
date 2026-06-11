#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <deque>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <bitset>

using namespace std;
using ll = long long;

int main() {
    int n, d, a;
    cin >> n >> d >> a;
    vector<int> x(n), h(n);
    vector<int> order(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> h[i];
        order[i] = i;
    }
    sort(order.begin(), order.end(), [&x](int v1, int v2) {
        return x[v1] < x[v2];
    });
    deque<pair<int, int>> queue;
    ll sum = 0;
    ll res = 0;
    for (int i : order) {
        while (!queue.empty() && queue.front().first + d < x[i]) {
            sum -= queue.front().second * a;
            queue.pop_front();
        }
        if (h[i] > sum) {
            int need = h[i] - (int) sum;
            int count = (need + a - 1) / a;
            res += count;
            sum += count * a;
            queue.emplace_back(x[i] + d, count);
        }
    }
    cout << res << "\n";
    return 0;
}
