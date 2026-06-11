#include <bits/stdc++.h>

using namespace std;
const int MAXN = 3 * 1e5 + 15;
int cntx[MAXN], cnty[MAXN], x[MAXN], y[MAXN];
int main() {

    int h, w, m;
    scanf("%d %d %d", &h, &w, &m);

    for(int i = 1; i <= m; i++) {
        scanf("%d %d", &x[i], &y[i]);

        cntx[x[i]]++; cnty[y[i]]++;
    }

    int fx = 0, fy = 0, sumx = 0, sumy = 0;

    for(int i = 1; i <= h; i++) {
        fx = max(fx, cntx[i]);
    }
    for(int i = 1; i <= h; i++) {
        if(cntx[i] == fx) sumx++;
    }

    for(int i = 1; i <= w; i++) {
        fy = max(fy, cnty[i]);
    }
    for(int i = 1; i <= w; i++) {
        if(cnty[i] == fy) sumy++;
    }

    int cnt = 0;
    for(int i = 1; i <= m; i++) {
        if(cntx[x[i]] == fx && cnty[y[i]] == fy) cnt++;
    }

    printf("%d\n", fx + fy - (cnt == 1ll * sumx * sumy ? 1 : 0));

    return 0;
}
