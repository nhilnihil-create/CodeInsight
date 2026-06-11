#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
typedef unordered_set<int> si;
typedef pair<int, int> pp;

#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
#define all(e) (e).begin(), (e).end()
#define pb push_back


template <typename T>
void printV(vector<T> A) {
    if (A.empty()) cerr << "EMTPY\n";
    else { 
        cerr << "[";
        for (int i = 0; i < A.size() -1 ; ++i) {
            cerr << A[i] << ", ";
        }
        if (A.size()) cerr << A.back() << "]\n";
    }
}


template <typename T>
void printVV(vector<vector<T>> A) {
    cerr << "[";
    for (auto v : A) {
        printV<T>(v);
    }
    cerr << "]";
}

template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
    cerr << name << ": " << arg1 << endl;
}

template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&& ...args) {
    const char* comma = strchr(names + 1, ',');
    cerr.write(names, comma - names) << ": " << arg1 << " |";
    __f(comma + 1, args...);
}

struct Info { 
    int node, dist;
};

const int MAXN = 1e5 + 10;
int dp[MAXN][3];


int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m; cin >> n >> m;
    auto graph = vvi(n);
    memset(dp,-1,sizeof(dp));
    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        u--, v--;
        graph[u].pb(v);
    }
    int s, t; cin >> s >> t;
    s--, t--;
    queue<Info> q;
    q.push({s,0});
    dp[s][0] = 0;
    while (!q.empty()) {
        Info& i  = q.front(); q.pop();
        int node = i.node, dist = i.dist;//ith = i.ith, acc = i.acc;
        for (auto neigh: graph[node]) {
            //int nith = (ith+1) % 3, nacc = acc + (ith == 0);
            int D = dist+1;
            if (dp[neigh][D%3] == -1 || dp[neigh][D%3] > D) {
                dp[neigh][D%3] = D;
                q.push({neigh, D});//nith, nacc});
            }
        }
    }

    if (dp[t][0] !=- 1) cout << dp[t][0] / 3 << endl;
    else cout << -1 << endl;



    return 0;
}