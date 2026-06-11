#include <iostream>
#include <sstream>
#include <stack>
#include <iomanip>
#include <numeric>
#include <string>
#include <cstring>
#include <algorithm>
#include <functional>
#include <cstdlib>
#include <map>
#include <set>
#include <vector>
#include <utility>
#include <queue>
#include <cmath>

#define BEGIN(x) x.begin()
#define END(x) x.end()
#define ALL(x) BEGIN(x), END(x)
#define PAIR make_pair
#define VEC(type) vector<type >
#define endl '\n'

#define FOR(i, A, B) for(auto i = (A);i != (B); i++)
#define FORD(i, A, B) for(auto i = (A);i != (B); i--)

#define READRANGE(begin, end) FOR(it, begin, end) cin >> *it
#define READVEC(V) READRANGE(BEGIN(V), END(V))

using namespace std;

typedef long long lint;
typedef pair<int, int> Pii;
typedef pair<int, lint> Pil;
typedef pair<lint, lint> Pll;
typedef pair<lint, int> Pli;

// ---- BEGIN LIBRARY CODE ----
// ---- END LIBRARY CODE ----
void io_init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
};

int main(int argc, char **argv)
{
    io_init();

    // Actual program code starts here.
    int N, M;
    cin >> N >> M;
    VEC(VEC(int)) edges(N);
    FOR(i, 0, M) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        edges[u].push_back(v);
    }

    VEC(VEC(int)) Dist(N, VEC(int)(3, -1));
    int S, T;
    cin >> S >> T;
    S--; T--;

    queue<Pii> bfsQ;
    auto add = [&Dist, &bfsQ, &edges](int node, int turn, int newdist)
    {
        if (Dist[node][turn] >= 0)
            return;

        Dist[node][turn] = newdist;
        bfsQ.push(Pii(node, turn));
    };

    add(S, 0, 0);
    while (!bfsQ.empty()) {
        Pii nodet = bfsQ.front();
        bfsQ.pop();
        int node = nodet.first, turn = nodet.second;
        for (int next : edges[node])
            add(next, (turn + 1) % 3, Dist[node][turn] + 1);
    }

    if (Dist[T][0] < 0)
        cout << -1;
    else
        cout << Dist[T][0] / 3;
    cout << "\n";
    return 0;
};
