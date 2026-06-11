#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
using namespace std;

const int MAX = 100010;


int n;
int par[MAX];
int deep[MAX];
vector<int> G[MAX];

void init() {
    for (int i = 0; i < n; i++) {
        G[i].clear();
        par[i] = -1;
        deep[i] = 0;
    }
}

int findRoot() {
    for (int i = 0; i < n; i++) {
        if (par[i] == -1) return i;
    }
    return 0;
}

void dfs(int r, int d) {
    deep[r] = d;
    for (int i = 0; i < G[r].size(); i++) {
        dfs(G[r][i], d+1);
    }
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    scanf("%d", &n);
    init();
    for (int i = 0; i < n; i++) {
        int poi, k;
        scanf("%d %d", &poi, &k);
        for (int j = 0; j < k; j++) {
            int nex = 0;
            scanf("%d", &nex);
            par[nex] = poi;
            G[poi].push_back(nex);
        }
    }
    int root = findRoot();
    dfs(root, 0);
    for (int i = 0; i < n; i++) {
        printf("node %d: parent = %d, depth = %d, ", i, par[i], deep[i]);
        if (i == root) printf("root, ");
        else if (G[i].empty()) printf("leaf, ");
        else printf("internal node, ");
        printf("[");
        for (int j = 0; j < G[i].size(); j++) {
            if (j > 0) printf(", ");
            printf("%d", G[i][j]);
        }
        printf("]\n");
    }
    return 0;
}