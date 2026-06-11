
#pragma GCC optimize ("O3")

#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include <prettyprint.hpp>
#define debug(...)  cerr << "[" << #__VA_ARGS__ << "]: ", d_err(__VA_ARGS__);
#else
#define debug(...) 83;
#endif

void d_err() {
    cerr << endl;
}

template <typename H, typename... T>
void d_err(H h, T... t) {
    cerr << h << " ";
    d_err(t...);
}

template <typename T>
void print(T x) {
    cout << x << endl;
}

#define ALL(x) (x).begin(), (x).end()
#define FOR(i, m, n) for (int i = (m); i < (n); ++i)
#define REVFOR(i, m, n) for (int i = (n - 1); i >= (m); --i)
#define REP(i, n) FOR(i, 0, n)
#define REVREP(i, n) REVFOR(i, 0, n)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define bcnt __builtin_popcountll

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<ll,ll> Pll;
typedef pair<int,int> Pin;

ll INF = 1e16;
int inf = 1e9;
ll MOD = 1e9+7;

struct Edge {
    int to;
    int idx;
    Edge(int t, int i) : to(t), idx(i) {}
};

vector<vector<Edge>> E(1e5 + 1);
vector<int> color(1e5 + 1);


int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    
    int N;
    cin >> N;

    vi A(N), B(N);
    REP(i, N - 1) {
        cin >> A[i] >> B[i];
        A[i]--; B[i]--;

        E[A[i]].eb(B[i], i);
        E[B[i]].eb(A[i], i);
    }

    queue<pair<int, int>> q;
    q.emplace(0, 0);
    vector<bool> used(N);

    int c_max = 0;
    while(!q.empty()) {
        auto p = q.front(); q.pop();
        used[p.fi] = true;

        int no = p.se;
        int c = 1;
        for(auto e: E[p.fi]) {
            if (used[e.to]) continue;

            if (c == no) c++;

            color[e.idx] = c;
            q.emplace(e.to, c);
            ++c;

        }
        c_max = max(c, c_max);
    }

    print(c_max - 1);
    REP(i, N - 1) print(color[i]);
    
}
