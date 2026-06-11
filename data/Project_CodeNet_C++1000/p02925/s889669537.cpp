#include<bits/stdc++.h>

using namespace std;
using ll = long long;
const ll mod = 1000000007;

const int MAXN = 1005;
const int MAXV = MAXN * MAXN;

vector<vector<int>> hen;
int id[MAXN][MAXN];
int toid(int i, int j) {
    if(i > j)swap(i, j);
    return id[i][j];
}

vector<int> dist(MAXV);
vector<int> seen(MAXV); // 0 : まだ見てない / 1 : 計算中 / 2 : 計算済み

int dfs(int u) {
    if(seen[u]){
        if(seen[u] == 1)return -1;
        else return dist[u];
    }

    seen[u] = 1;
    dist[u] = 1;
    for(auto i : hen[u]){
        int res = dfs(i);
        if(res == -1)return -1;
        dist[u] = max(dist[u], res + 1);
    }
    seen[u] = 2;
    return dist[u];
}




int main()
{
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n - 1));
    for(int i = 0; i < n; i++)for(int j = 0; j < n - 1; j++)cin >> a[i][j], a[i][j]--;
    int m = 0;
    for(int i = 0; i < n; i++)for(int j = i + 1; j < n; j++)id[i][j] = m++;
    hen.resize(m);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n - 1; j++)a[i][j] = toid(i, a[i][j]);
        for(int j = 0; j < n - 2; j++)hen[a[i][j]].push_back(a[i][j + 1]);
    }
    cerr << "yay" << endl;
    for(int i = 0; i < m; i++){
        int res = dfs(i);
        if(res == -1){
            cout << -1 << endl;
            return 0;
        }
    }
    cerr << "yay" << endl;
    cout << *max_element(dist.begin(), dist.end()) << endl;
}