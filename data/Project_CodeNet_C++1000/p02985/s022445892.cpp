#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
const int mod = 1000000007;
int n, k;
int node[100005]={0};
vector< vector<int> > to(100005);
void dfs(int cur, int level, int prev = -1) {
    int tmp = (level==0?1:2);
    int cnt = 0;
    for(int next : to[cur]) {
        if(next != prev) {
            node[next] = k - tmp -cnt++;
            dfs(next, level+1, cur);
        }
    }
}
int main() {
    cin >> n >> k;
    rep(i, n-1) {
        int a, b; cin >> a >> b;
        to[a-1].push_back(b-1);
        to[b-1].push_back(a-1);
    }
    node[0] = k;
    dfs(0,0);
    /*rep(i, n) {
        printf("%d ",node[i]);
    }puts("");*/
    ll ans = 1;
    rep(i, n) {
        ans = (ans*node[i])%mod;
    }
    cout << ans << endl;
}
