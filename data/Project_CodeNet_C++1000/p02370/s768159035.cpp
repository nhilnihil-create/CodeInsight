#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <numeric>
#include <string>
#include <cmath>
#include <iomanip>
#include <queue>
#include <list>
#include <set>
#include <stack>
#include <cctype>
#include <cmath>
#include <bitset>

using namespace std;

/* typedef */
typedef long long ll;

/* constant */
const int INF = 1 << 30;
const int NIL = -1;
const int MAX = 10000;
const int mod = 1000000007;
const double pi = 3.141592653589;
const int WHITE = 0;
const int GRAY = 1;
const int BLACK = 2;

/* global variables */
vector<int> out;
vector< vector<int> > Adj(MAX);
vector<int> indeg(MAX, 0), color(MAX, WHITE);
/* function */
void bfs(int u);

/* main */
int main() {

    int V, E, v, u;
    cin >> V >> E;

    for (int i = 0; i < E; i++) {
        cin >> v >> u;
        Adj[v].push_back(u);
        indeg[u]++;
    }

    for (int u = 0; u < V; u++) {
        if (indeg[u] == 0 && color[u] == WHITE) {
            bfs(u);
        }
    }

    for (auto o : out)
        cout << o << '\n';

}

void bfs(int u) {
    queue<int> Q;
    int s, t;
    Q.push(u);
    color[u] = GRAY;
    while (!Q.empty()) {
        s = Q.front();
        Q.pop();
        out.push_back(s);

        for (int i = 0; i < Adj[s].size(); i++) {
            t = Adj[s][i];
            indeg[t]--;
            if (indeg[t] == 0 && color[t] == WHITE) {
                color[t] = GRAY;
                Q.push(t);
            }
        }
    }
}
