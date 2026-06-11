#include <bits/stdc++.h>
using namespace std;
template <class T> inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T> inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return 1;
    }
    return 0;
}
void print() { cout << "\n"; }
template <class T> void print(const T &x) { cout << x << "\n"; }
template <class T, class... Args> void print(const T &x, const Args &... args) {
    cout << x << " ";
    print(args...);
}
template <class T> void printVector(const vector<T> &v) {
    for(const T &x : v) {
        cout << x << " ";
    }
    cout << "\n";
}
using ll = long long;

#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
const double EPS = 1e-7;
const int INF = 1 << 30;
const ll LLINF = 1LL << 60;
const double PI = acos(-1);
constexpr int MOD = 1000000007;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

//-------------------------------------

using P = pair<int, int>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n - 1));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n - 1; j++) {
            cin >> a[i][j];
            a[i][j]--;
        }
    }
    map<P, int> toV;
    {
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                toV[P(i, j)] = cnt++;
            }
        }
    }
    int N = n * (n - 1) / 2;
    vector<vector<int>> g(N);
    vector<int> h(N, 0); // 入次数
    for(int i = 0; i < n; i++) {
        for(int j = 1; j < n - 1; j++) {
            int u, v;
            u = toV[(i < a[i][j - 1] ? P(i, a[i][j - 1]) : P(a[i][j - 1], i))];
            v = toV[(i < a[i][j] ? P(i, a[i][j]) : P(a[i][j], i))];
            g[u].emplace_back(v);
            h[v]++;
        }
    }
    vector<int> topo;
    {
        stack<int> st;
        for(int i = 0; i < N; i++) {
            if(h[i] == 0) {
                st.push(i);
            }
        }
        while(st.size()) {
            int i = st.top();
            st.pop();
            topo.emplace_back(i);
            for(const int &j : g[i]) {
                h[j]--;
                if(h[j] == 0) {
                    st.push(j);
                }
            }
        }
    }
    if(topo.size() != N) {
        print(-1);
        return 0;
    }
    vector<int> dp(N, -INF);
    auto dfs = [&](auto &&dfs, int v) -> int {
        if(dp[v] != -INF) {
            return dp[v];
        }
        int res = 1;
        for(const auto &u : g[v]) {
            chmax(res, dfs(dfs, u) + 1);
        }
        return dp[v] = res;
    };
    int ans = 0;
    for(int i = 0; i < N; i++) {
        chmax(ans, dfs(dfs, i));
    }
    print(ans);
}