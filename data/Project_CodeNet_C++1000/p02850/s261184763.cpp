#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>
#include <set>
#include <cassert>

#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;
typedef long long int ll;
const ll INF = 1000000000000000000;
const double PI = acos(-1);

struct Edge {
    int id;
    int to;
};

vector<vector<Edge>> node;
vector<int> c;
int max_c = 0;

void dfs(int n, int p, int c_p) {
    int c_now = 0;
    rep(i, node[n].size()) {
        Edge edge = node[n][i];       // 今見ている辺
        if (edge.to == p) continue;   // 今見ている辺がn->pの辺だったらスキップ
        c_now++;
        if (c_now == c_p) c_now++;    // p->nの辺と同じ色だったら色を1つ進める
        c[edge.id] = c_now;           // 色を塗る
        dfs(edge.to, n, c_now);
    }
    max_c = max(max_c, c_now);
    return;
}

int main()
{
    int n;
    cin >> n;
    node.resize(n);
    c.resize(n - 1);
    rep(i, n-1) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        Edge edge1 = { i, b };  // a->bの辺
        Edge edge2 = { i, a };  // b->aの辺
        node[a].push_back(edge1);
        node[b].push_back(edge2);
    }
    dfs(0, -1, -1);
    cout << max_c << endl;
    rep(i, n - 1) {
        cout << c[i] << endl;
    }
    return 0;
}