#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iomanip>
#include <numeric>
#include <queue>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> v(n + 1, vector<int>(0));
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }
    int node = 0;
    for (int i = 1; i <= n; i++) {
        if (v[i].size() == 1) {
            node = i;
            break;
        }
    }
    vector<int> visited(n + 1, 0);
    visited[node] = 1;
    long long int res = (long long int)node * (long long int)(n - node + 1);
    vector<int> v1, v2;
    v1.push_back(node);
    while (v1.size() > 0) {
        v2.clear();
        for (auto now : v1) {
            for (auto next : v[now]) {
                if (visited[next] == 0) {
                    if (now < next) {
                        res += (long long int)(next - now) * (long long int)(n - next + 1);
                    } else {
                        res += (long long int)(now - next) * (long long int)next;
                    }
                    visited[next] = 1;
                    v2.push_back(next);
                }
            }
        }
        v1 = v2;
    }
    cout << res << endl;
}
