#include <bits/stdc++.h>

#define F first
#define S second
#define MP make_pair
#define pb push_back
#define all(a) a.begin(), a.end()
#define lcm(a, b) (a)/__gcd((a),(b))*(b)
#define endl '\n'

using namespace std;

typedef long long LL;
typedef pair<int, int> P;
typedef pair<LL, LL> LP;

static const int INF = INT_MAX;
static const LL LINF = LLONG_MAX;
static const int MIN = INT_MIN;
static const LL LMIN = LLONG_MIN;
static const int MOD = 1000000007;
static const int SIZE = 200005;

const int dx[] = {0, -1, 1, 0};
const int dy[] = {-1, 0, 0, 1};

vector<int> Div(int n) {
    vector<int> ret;
    for(int i = 1; i * i <= n; ++i) {
        if(n % i == 0) {
            ret.pb(i);

            if(i * i != n) ret.pb(n / i);
        }
    }
    sort(all(ret));
    return ret;
}

int bfs(int s, int t);

vector< P > graph[SIZE];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    while(m--) {
        int u, v;
        cin >> u >> v;
        graph[u].pb(MP(v, 1));
        graph[u].pb(MP(v, 2));
        graph[u].pb(MP(v, 3));

    }

    int s, t;
    cin >> s >> t;
    int res = bfs(s, t);
    if(res != -1) res /= 3;
    cout << res << endl;

    return 0;
}

int bfs(int s, int t) {
    queue<P> q;
    q.push(MP(s, 0));

    bool isvisit[SIZE][4];
    int cost[SIZE][3];
    for(int i = 0; i < SIZE; ++i) {
        for(int j = 0; j < 4; ++j) {
            isvisit[i][j] = false;
            cost[i][j] = 0;

        }
    }
    isvisit[s][0] = true;
    while(!q.empty()) {
        P p = q.front(); q.pop();

        for(int i = 0; i < graph[p.F].size(); ++i) {
            int to, pat;
            to = graph[p.F][i].F;
            pat = graph[p.F][i].S;
            if(p.S == 3 && pat != 1 ||
               p.S == 2 && pat != 3 ||
               p.S == 1 && pat != 2 ||
               p.S == 0 && pat != 1 ) {
                continue;

            }

            if(isvisit[to][pat]) {
                continue;

            }
            isvisit[to][pat] = true;
            if(to == t && pat == 3) {
                return cost[p.F][2] + 1;

            }
            cost[to][pat] = cost[p.F][p.S] + 1;
            q.push(MP(to, pat));

        }
    }

    return -1;
}
