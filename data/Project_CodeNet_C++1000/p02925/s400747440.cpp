#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i) 
#define PI acos(-1)

using namespace std;
using ll = long long;
using P = pair<int, int>;
using LP = pair<ll, ll>;

int dfs(int v, vector<vector<int>>& to, vector<bool>& visited, vector<int>& day) {
    if (visited[v]) return day[v];
    visited[v] = true;
    
    int ret = 1;
    for (auto e : to[v]) {
        int res = dfs(e, to, visited, day);
        if (res == -1) return -1;
        ret = max(ret, res + 1);
    }
    day[v] = ret;
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin>>N;
    int max_n = N * (N - 1) / 2;
    vector<vector<int>> as(N, vector<int>(N));
    rep(i, N) {
        rep(j, N - 1) {
            int a;
            cin>>a; a--;
            as[i][j] = a;
        }
    }
    vector<vector<int>> id(N, vector<int>(N));
    int d = 0;
    rep(i, N) rep(j, N) {
        if (i < j) id[i][j] = d++;
    }

    vector<vector<int>> to(max_n);
    rep(i, N) {
        rep(j, N - 1) {
            if (i > as[i][j]) as[i][j] = id[as[i][j]][i];
            else as[i][j] = id[i][as[i][j]];
        }
        rep(j, N - 2) {
            to[as[i][j + 1]].push_back(as[i][j]);
        }
    }

    int ans = 0;
    vector<bool> visited(max_n);
    vector<int> day(max_n, -1);
    rep(i, max_n) {
        int res = dfs(i, to, visited, day);
        if (res == -1) {
            cout<<-1<<endl;
            return 0;
        }
        ans = max(ans, res);
    }
    cout<<ans<<endl;
}