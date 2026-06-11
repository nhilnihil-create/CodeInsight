#include <bits/stdc++.h>
//#include <ext/numeric>


using namespace std;
//using namespace __gnu_cxx;

const int MAXN = (int)1e5 + 5;
vector<int> adjList[MAXN];
bool vis[MAXN];

void dfs(int u) {
    vis[u] = 1;
    for (int v : adjList[u]) {
        if (!vis[v])
            dfs(v);
    }
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0), cout.precision(10), cout << fixed;

    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    vector<int> ans;
    int i = 0;
    while (i < n) {
        int x = min(m, n - i);
        while (x && s[i + x] == '1')
            --x;
        if (x == 0) {
            cout << -1 << '\n';
            return 0;
        }
        ans.push_back(x);
        i += x;
    }

    reverse(ans.begin(), ans.end());

    for (int x : ans)
        cout << x << ' ';
    cout << '\n';




    return 0;
}