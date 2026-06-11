#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<ll> vll;
typedef vector<vll> vvl;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector<pair<int, int> > vp;
typedef pair<int, int> pr;
typedef tuple<int, int, int> ti;

#define FOR(i, a, b) for (int i = (a), _b = (b); i < _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i > _a; i--)
#define pb push_back
#define print(v) cout << v << '\n'
#define pr_vec(v)   for (auto i: v) cout << i << ' '
#define vin(v)  for (auto &i: v)    cin >> i

ld pi = 3.141592653589793238;
ll M = 1e9 + 7;

int gcd(int a, int b) {
    if (a == 0) return b;

    return gcd(b % a, a);
}

bool is_prime(ll n) {
    if (n == 2) return true;
    if (n < 2) return false;
    if (n % 2 == 0) return false;

    for (int i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0) return false;
    }

    return true;
}

bool is_palindrome(string s) {
    return equal(s.rbegin(), s.rend(), s.begin());
}

void dfs(int s, vector<bool>& visited, vvi& graph) {
    if (visited[s]) return;
    visited[s] = true;
    print(s);

    for (auto i: graph[s])  dfs(i, visited, graph);
}

vi bfs(int x, vector<bool>& visited, vvi& graph) {
    vi distance(visited.size(), 0);
    queue<int> q;
    visited[x] = true;
    q.push(x);

    while (!q.empty()) {
        int s = q.front();
        q.pop();

        for (auto u: graph[s]) {
            if (visited[u]) continue;
            visited[u] = true;
            distance[u] = distance[s] + 1;
            q.push(u);
        }
    }

    return distance;
}

void add_un_edge(vvi& graph, int a, int b) {
    graph[a].pb(b);
    graph[b].pb(a);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t, n, m, k, q, x, y;
    string s;
    bool flag;

	ll MOD = 998244353;

    cin >> n >> m;
	vll a(n + 1);
	FOR (i, 1, n + 1)	cin >> a[i];

	vvl dp(n + 1, vll(m + 1, 0));

	dp[0][0] = 1;

	FOR (i, 1, n + 1) {
		FOR (j, 0, m + 1) {
			dp[i][j] = 2ll * dp[i - 1][j];
			if (j >= a[i])	dp[i][j] += dp[i - 1][j - a[i]];
			dp[i][j] %= MOD;
		}
	}

	print(dp[n][m]);

    return 0;
}