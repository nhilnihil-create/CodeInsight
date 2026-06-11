#include<bits/stdc++.h>
using namespace std;
#define arep(i,x,n) for(int i=int(x);i<(int)(n);i++)
#define rep(i,n) for(long long i = 0;i < n;++i)
#define pi 3.141592653589793
#define eps 0.00000001
#define INF 1e9+7  
using ll = long long;
using P = pair<int, int>;
using lP = pair<ll, ll>;
using fP = pair<double, double>;
ll const mod = 998244353;
const ll MAX = 300000;
vector<vector<int>>node;
vector<P>edge;
int get_clo(int& a, int b) {
    if (a == b)return ++a;
    else return a;
}
map<P, int>mp;
int dfs(int a, int f, int pc) {
    int cl = 0;
    int mx = 0;
    for (int x : node[a]) {
        if (x == f)continue;
        cl++;
        int s = x, t = a;
        if (s < t)swap(s, t);
        mp[P(s, t)] = get_clo(cl, pc);
        mx = max(mx, dfs(x, a, mp[P(s, t)]));
    }
    return max(mx, cl);
}

int main() {
    int n;
    cin >> n;
    node.resize(n);
    edge.resize(n);
    rep(i, n - 1) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        node[a].push_back(b);
        node[b].push_back(a);
        if (a < b)swap(a, b);
        edge[i] = P(a, b);
    }
    int ans = dfs(0, 0, 0);
    cout << ans << endl;
    rep(i, n - 1) {
        cout << mp[edge[i]] << endl;
    }
    return 0;
}