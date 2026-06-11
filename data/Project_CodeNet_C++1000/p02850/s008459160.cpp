#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
using Graph = vector<vector<int>>;
#define MOD 1000000007
#define MOD2 998244353
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long ll;
typedef pair<ll, ll> P;


vector<int> g[100010];
map<pair<int,int>, int> mp;
bool seen[100010];
int A[100010], B[100010];


int main(){
    int n;
    cin >> n;
    rep(i, n - 1){
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
        A[i] = a;
        B[i] = b;
    }
    int mx = 0;
    rep(i, n){
        int s = g[i].size();
        mx = max(mx, s);
    }
    int ini;
    rep(i, n) if (g[i].size() == mx) ini = i;

    queue<pair<int,int>> que; // node, color of edge
    que.push(make_pair(ini, 0));

    while(!que.empty()){
        pair<int,int> p = que.front();
        int v = p.first;
        int c = p.second;
        seen[v] = true;
        que.pop();
        int cnt = 1;
        for (auto nv : g[v]) {
            if (seen[nv]) continue;
            if (cnt == c) cnt++; //if the path is same
            mp[make_pair(v,nv)] = cnt;
            mp[make_pair(nv,v)] = cnt;
            que.push(make_pair(nv, cnt));
            cnt++;
        }
    }

    cout << mx << endl;
    rep(i, n - 1){
        cout << mp[make_pair(A[i], B[i])] << endl;
    }

    return 0;
}