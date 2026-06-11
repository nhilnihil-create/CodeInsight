#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int n, m;
vector<vector<int>> hen;
vector<bool> seen;
vector<int> top;

void dfs(int v) {
    if(seen[v]) return;
    seen[v] = true;
    for(auto i : hen[v]) {
        dfs(i);
    }
    top.push_back(v);
}

int main()
{
    cin >> n >> m;
    hen.resize(n);
    seen.resize(n);
    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        hen[a].push_back(b);
    }
    for(int i = 0; i < n; i++)dfs(i);
    reverse(top.begin(), top.end());
    for(auto i : top)cout << i << endl;
}
