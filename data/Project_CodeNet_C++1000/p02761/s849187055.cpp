#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m; scanf("%d%d", &n, &m);
    int ret = 1000;
    vector<int> v(n+1, 0), t(n+1, 0);


    for (int i = 0; i < m; i++) {
        int s, c;
        scanf("%d%d", &s, &c);
        if (n!=1 && s==1 && c==0) ret = -1;
        if (t[s]==1 && v[s]!=c) ret = -1;
        t[s] = 1;
        v[s] = c;
    }
    if (ret == 1000) {
        if (t[1]==0) {
            ret = (n==1) ? 0 : 1;
        }
        else {
            ret = v[1];
        }
        for (int i = 2; i <= n; i++) {
            ret *= 10;
            ret += (t[i]==0) ? 0 : v[i];
        }
    }

    printf("%d\n", ret);
    return 0;
}