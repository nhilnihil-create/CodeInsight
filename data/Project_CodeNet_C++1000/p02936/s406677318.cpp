#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i,n) for(int i=0; i<(n); i++)
#define REP2(i,x,n) for(int i=x; i<(n); i++)
#define PRINT(x) cout<<(x)<<endl
#define INF 1000000000000 // 10^12
#define MOD 1000000007 // 10^9+7
#define PB push_back
#define MP make_pair

const int MAX_N = 200000;

int N, Q, a, b, p, x;

vector<int> G[MAX_N];
int cnt[MAX_N];
bool visited[MAX_N];

void dfs(int);

int main() {
    cin >> N >> Q;

    // make G
    REP(i, N-1) {
        cin >> a >> b;
        a--; b--;
        G[a].PB(b);
        G[b].PB(a);
    }

    // make cnt
    REP(i, Q) {
        cin >> p >> x;
        p--;
        cnt[p] += x;
    }

    // init visited
    REP(i, N) visited[i] = false;

    // DFS
    dfs(0);

    // output
    printf("%d", cnt[0]);
    REP2(i, 1, N) printf(" %d", cnt[i]);
    printf("\n");

    return 0;
}

void dfs(int pos) {
    visited[pos] = true;
    REP(i, G[pos].size()) {
        int to = G[pos][i];
        if (visited[to]) continue;
        cnt[to] += cnt[pos];
        dfs(to);
    }
    return;
}