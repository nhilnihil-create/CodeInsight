#include <iostream>
#include <vector>

using namespace std;

typedef struct edge_ {
    int num;
    int from;
    int to;
} edge;

vector<int> color;
vector<vector<edge> > G;

void dfs(int s, int p, int c) {
    int tmp = 1;
    for (auto e: G[s]) {
        if (e.to == p)
            continue;

        if (tmp == c)
            tmp++;
        color[e.num] = tmp;
        dfs(e.to, s, tmp);
        tmp++;
    }
}

int main() {
    int n;  cin >> n;
    G.resize(n);
    color.resize(n-1);
    for (int i = 0; i < n-1; i++) {
        int a, b;   cin >> a >> b;
        edge e1 = {i, a-1, b-1}, e2 = {i, b-1, a-1};
        G[a-1].push_back(e1);
        G[b-1].push_back(e2);
    }

    int cnt = 0;
    for (int i = 0; i < n; i++)
        cnt = max(cnt, (int)(G[i].size()));
    cout << cnt << endl;

    dfs(0, -1, -1);

    for (int i = 0; i < n-1; i++)
        cout << color[i] << endl;

    return 0;
}