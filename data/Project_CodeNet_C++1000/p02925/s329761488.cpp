#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i ++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll,ll> PL;
const ll MOD = 1e9 + 7;
const ll INF = 1e10;

const int MAXN = 1005;
const int MAXV = MAXN * (MAXN - 1)/2;
vector<vector<int>> G(MAXV);
vector<vector<int>> id(MAXN,vector<int>(MAXN));

int toID(int i,int j) {
    if (i > j) swap(i,j);
    return id[i][j];
}

vector<int> dp(MAXV,-1);
vector<bool> finished(MAXV,false);

int dfs(int v) {
    if (dp[v] != -1) {
        if (!finished[v]) {
            return -1;
        }
        return dp[v];
    }
    dp[v] = 1;
    for (int e : G[v]) {
        int res = dfs(e);
        if (res == -1) return -1;
        dp[v] = max(dp[v], dfs(e) + 1);
    }
    finished[v] = true;
    return dp[v];
}

int main() {
    int n; cin >> n;
    vector<vector<int>> a(n,vector<int>(n - 1));
    rep(i,n)rep(j,n - 1) {
        cin >> a[i][j];
        a[i][j] --;
    }

    int v = 0;
    rep(i,n)rep(j,n) {
        if (i < j) id[i][j] = v++;
    }

    rep(i,n) {
        rep(j,n - 1) {
            a[i][j] = toID(i,a[i][j]);
        }
        rep(j,n - 2) {
            G[a[i][j + 1]].push_back(a[i][j]);
        }
    }

    int ans = 0;
    rep(i,v) {
        int res = dfs(i);
        if (res == -1) {
            ans = -1;
            break;
        }
        ans = max(ans,dfs(i));
    }

    cout << ans << endl;
}