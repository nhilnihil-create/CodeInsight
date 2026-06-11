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

ll mod = 1e9 + 7;
ll ans;
ll n,k;
vvi graph;


void dfs(int node, int parent, ll pos) {
    if (!ans) return;
    ans = ans * max(0LL,pos);
    ans %= mod;
    int x = k - ((parent == 0) ? 1 : 2);
    for (auto u : graph[node]) {
        if (u == parent) continue;
        dfs(u, node, x);
        x--;
    }
}

void solve() {
   cin >> n >> k;
   graph = vvi(n+1);
   ans = 1;

   for (int i = 1; i < n; ++i) {
       int a, b; cin >> a >> b;
       graph[a].push_back(b);
       graph[b].push_back(a);
   }
   dfs(1,0,k);
   cout << ans << endl;
}

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}

