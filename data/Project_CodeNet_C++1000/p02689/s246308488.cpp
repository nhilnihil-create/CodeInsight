#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int MOD = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> obs(n);
    vector<int> adj[n];
    vector<int> score(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> obs[i];
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
        if (obs[a] > obs[b])
            score[a]++;
        else if (obs[b] > obs[a])
            score[b]++;
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
        if (score[i] == adj[i].size())
            ans++;
    cout << ans << endl;
	return 0;
}