// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_B

#include <iostream>
#include <iomanip>

#include <vector>
#include <string>
#include <iterator>
#include <algorithm>
#include <queue>

typedef long long ll;
const long double PI = (acos(-1));
const long long MOD = 1000000007;
#define rep(i,n) REP(i,0,n)
#define REP(i,x,n) for(int i=x;i<n;++i)

using namespace std;

// change min/max
template<class T> inline bool chMin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chMax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

template<class T> void output(std::vector<T> & A) {
    const int n = A.size();
    for (int i = 0; i < n - 1; ++i) {
        std::cout << A[i] << " ";
    }
    std::cout << A[n - 1] << std::endl;
}

const int WHITE = 0;
const int GRAY = 1;
const int BLACK = 2;
vector<vector<int>> M;
vector<int> colour, d;
int tt = 0;
queue<int> que;

void bfs(int u) {
    que.push(u);
    colour[u] = GRAY;

    while (!que.empty()) {
        const int v = que.front(); que.pop();
        for (int s : M[v]) {
            if (colour[s] == WHITE) {
                que.push(s);
                d[s] = d[v] + 1;
                colour[s] = GRAY;
            }
        }
        colour[v] = BLACK;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout << std::fixed << std::setprecision(15);

    // populate M
    int n; cin >> n;
    M = vector<vector<int>>(n);
    colour = vector<int>(n, 0);
    d = vector<int>(n, -1);

    rep(i, n) {
        int from; cin >> from; --from;
        int m; cin >> m;
        rep(j, m) {
            int to; cin >> to; --to;
            M[from].push_back(to);
            // M[to].push_back(from);
        }
    }

    // bfs
    d[0] = 0;
    bfs(0);

    rep(i, n) {
        cout << (i + 1) << " " << d[i] << endl;
    }

    return 0;
}

