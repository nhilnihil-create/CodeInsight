#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

int main() {
    int n, k, q;
    scanf("%d %d %d", &n, &k, &q);
    vector<int> p(n+1);
    rep(i, q) {
        int a;
        scanf("%d", &a);
        p[a]++;
    }
    rep(i, n+1) {
        if (i == 0) continue;
        if (k - q + p[i] > 0) printf("Yes\n");
        else printf("No\n");
    }
}