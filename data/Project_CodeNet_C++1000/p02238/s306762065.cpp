// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_B

#include <iostream>
#include <iomanip>

#include <vector>
#include <string>
#include <iterator>
#include <algorithm>

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
const int GRAY  = 1;
const int BLACK = 2;
vector<vector<int>> M;
vector<int> colour, d, f;
int tt = 0;

void dfs(int u) {
    // if black exit
    if (colour[u] == BLACK) return;
    
    // if white
    if (colour[u] == WHITE) {
        colour[u] = GRAY;
        d[u] = tt++;
        const int nb = M[u].size();
        rep(i, nb) {
            dfs(M[u][i]);
        }
        // if you are here, all the neigbours are already checked
        f[u] = tt++;
        colour[u] = BLACK;
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
    f = vector<int>(n, -1);

    rep(i, n) {
        int from; cin >> from; --from;
        int m; cin >> m;
        rep(j, m) {
            int to; cin >> to; --to;
            M[from].push_back(to);
            // M[to].push_back(from);
        }
    }

    // dfs
    rep(i, n) {
        if (colour[i] == WHITE) {
            dfs(i);
        }
    }

    rep(i, n) {
        cout << (i + 1) << " " << (d[i] + 1) << " " << (f[i] + 1) << endl;
    }

    return 0;
}

