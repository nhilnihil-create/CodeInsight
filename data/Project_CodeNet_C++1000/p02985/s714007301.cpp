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
vector<int> T[100010];
int N, K;
int dfs(int u, int p) {
    int ret = 1;
    int cnt = K - 2;
    if(p == -1) cnt++;
    for(auto to: T[u]) {
        if(to == p) continue;
        ret = (ret * dfs(to, u)) % mod;
        ret = (ret * cnt) % mod;
        cnt = max(cnt - 1, 0LL);
    }
    //cout << u << " " << ret << endl;
    return ret;
}

signed main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> K;
    rep(i, N - 1) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        T[a].push_back(b);
        T[b].push_back(a);
    }
    cout << (dfs(0, -1) * K) % mod << endl;

    return 0;
}
