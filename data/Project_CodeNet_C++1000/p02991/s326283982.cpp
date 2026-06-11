#include <iostream>
#include <vector>
#include <queue>

#define INF 1000000000

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int n, m, u, v, s, t;
    cin >> n >> m;
    vector< vector<int> > e(n + 1);
    for (int i = 0; i < m; ++i) cin >> u >> v, e.at(u).push_back(v);
    cin >> s >> t;
    vector< vector<int> > mem(n + 1, vector<int>(3, INF));
    mem.at(s).at(0) = 0;
    queue< pair<int, int> > q;
    q.push({s, 0});
    while (!q.empty()) {
        pair<int, int> next = q.front();
        q.pop();
        for (auto i = e.at(next.first).begin(); i != e.at(next.first).end(); ++i) {
            if (mem.at(*i).at((next.second + 1) % 3) > mem.at(next.first).at(next.second) + 1) {
                mem.at(*i).at((next.second + 1) % 3) = mem.at(next.first).at(next.second) + 1;
                q.push({*i, (next.second + 1) % 3});
            }
        }
    }
    cout << (mem.at(t).at(0) == INF ? -1 : mem.at(t).at(0) / 3) << endl;
    return 0;
}
