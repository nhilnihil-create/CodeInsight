#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <functional>
#include <algorithm>
#include <climits>
#include <cmath>
#include <iomanip>
using namespace std;
#define ll long long int
#define rep(i,n) for( int i = 0; i < n; i++ )
#define rrep(i,n) for( int i = n; i >= 0; i-- )
#define REP(i,s,t) for( int i = s; i <= t; i++ )
#define RREP(i,s,t) for( int i = s; i >= t; i-- )
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define INF 2000000000
#define mod 1000000007
#define INF2 1000000000000000000
#define int long long
vector<int> G[200010];
int add[200010];
int ans[200010];
void dfs(int x = 0, int p = -1, int num = 0) {
    num += add[x];
    ans[x] = num;
    for(auto& to: G[x]) {
        if(to == p) continue;
        dfs(to, x, num);
    }

}

signed main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, Q;
    cin >> N >> Q;
    rep(i, N - 1) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    rep(i, Q) {
        int p, x;
        cin >> p >> x;
        p--;
        add[p] += x;
    }
    dfs();
    rep(i, N) {
        if(i != 0) cout << " ";
        cout << ans[i]; 
    }
    cout << endl;

    return 0;
}
