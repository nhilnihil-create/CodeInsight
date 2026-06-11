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

const int MAX = 110;
int n;
int G[MAX][MAX];

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    memset(G, 0, sizeof(G));
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int p, k;
        scanf("%d %d", &p, &k);
        while (k--) {
            int ne = 0;
            scanf("%d", &ne);
            G[p][ne] = 1;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (j > 1) printf(" ");
            printf("%d", G[i][j]);
        }
        printf("\n");
    }
    return 0;
}