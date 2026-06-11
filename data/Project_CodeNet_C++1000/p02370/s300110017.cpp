#include <iostream>
#include <unordered_set>
#include <queue>
#include <unordered_map>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

    int n, m;
    cin >> n >> m;

    queue<int> q;
    unordered_map<int, int> mm;
    for (int i = 0; i < n; i++)
        mm[i] = 0;

    int f, t;
    unordered_set<int> g[n];
    for (int i = 0; i < m; i++) {
        cin >> f >> t;
        g[f].insert(t);
        mm[t]++;
    }

    for (const auto& p : mm) {
        if (!p.second)
            q.push(p.first);
    }

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        cout << v << "\n";

        for (int vv : g[v]) {
            int d = mm[vv]-1;
            if (!d)
                q.push(vv);
            mm[vv] = d;
        }
    }

    cout << endl;

	return 0;
}