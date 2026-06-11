#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cctype>
#include <cmath>
#include <bitset>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <cstring>
#include <sstream>
#include <iomanip>

using namespace std;

#define DUMP(x) cerr << #x << "=" << x << endl
#define DUMP2(x, y) cerr<<"("<<#x<<", "<<#y<<") = ("<<x<<", "<<y<<")"<< endl
#define BINARY(x) static_cast<bitset<16> >(x)

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define REP(i,m,n) for (int i=m;i<(int)(n);i++)

#define in_range(x, y, w, h) (0<=(int)(x) && (int)(x)<(int)(w) && 0<=(int)(y) && (int)(y)<(int)(h))
#define ALL(a) (a).begin(),(a).end()

typedef long long ll;
const int INF = 1e9;
typedef pair<int, int> PII;
int dx[4]={0, -1, 1, 0}, dy[4]={-1, 0, 0, 1};

typedef vector<vector<int>> Graph;
const int WHITE = 0;
const int GRAY  = 1;
const int BLACK = 2;

void dfs(Graph &G, int v, vector<int> &state, vector<int> &ord)
{
    // cerr << "IN : " << v << endl;
    state[v] = GRAY;

    for (auto u : G[v]) {
        if (state[u] != WHITE) continue;
        dfs(G, u, state, ord);
    }

    state[v] = BLACK;
    ord.push_back(v);
    // cerr << "OUT : " << v << endl;
}

vector<int> tsort(Graph &G)
{
    vector<int> ord, state(G.size(), WHITE);
    
    for (int i=0; i<G.size(); i++) {
        if (state[i] == WHITE) {
            dfs(G, i, state, ord);
        }
    }

    reverse(ord.begin(), ord.end());
    return ord;
}

int main()
{
    int V, E;
    cin >> V >> E;
    Graph G(V);
    rep(i, E) {
        int A, B;
        cin >> A >> B;
        G[A].push_back(B);
    }

    vector<int> ans = tsort(G);
    for (auto i : ans) cout << i << endl;
}