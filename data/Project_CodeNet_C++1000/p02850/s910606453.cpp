#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<deque>
#include<cmath>
#include<map>
#include<cstring>

using namespace std;
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LLINF = 1LL<<60;
#define P pair<ll, ll>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()

/* -- template -- */

int main() {
    int N;
    cin >> N;
    vector<vector<int>>G(N);
    int a[N - 1], b[N - 1];
    vector<P>v(N - 1);
    rep(i, N - 1) {
        cin >> a[i] >> b[i];
        --a[i], --b[i];
        G[a[i]].pb(b[i]);
        G[b[i]].pb(a[i]);
        v[i] = mp(a[i], b[i]);
    }
    vector<bool>visited(N, false);
    vector<int> parentColor(N, 0);
    map<P, int> color;
    visited[0] = true;
    queue<int>Q;
    Q.push(0);
    parentColor[0] = 0;
    while(!Q.empty()) {
        int q = Q.front(); Q.pop();
        int cur = 1;
        for(int next : G[q]) {
            if(visited[next])continue;
            if(cur == parentColor[q])++cur;
            Q.push(next);
            visited[next] = true;
            parentColor[next] = color[mp(q, next)] = color[mp(next, q)] = cur++;
        }
    }
    int maxv = 0;
    for(P i : v) {
        maxv = max(color[i], maxv);
    }
    cout << maxv << endl;
    for(P i : v) {
        cout << color[i] << endl;
    }
}
