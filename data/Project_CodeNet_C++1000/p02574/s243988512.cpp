#include <bits/stdc++.h>
using namespace std;

const int N = 1000001;
bool ip[N]; vector<int> ps;

int c[N];
vector<int> g[N];

int main(void) {
    fill_n(ip, N, 1); ip[1] = 0;
    for (int i = 2; i < N; ++i) {
        if (ip[i]) ps.push_back(i);
        for (int j : ps) {
            if (i * j >= N) break;
            ip[i * j] = 0;
            if (i % j == 0) break;
        }
    }

    for (int p : ps)
        for (int i = p; i < N; i += p)
            g[i].push_back(p);

    int n; scanf("%d", &n);
    int r = 0;
    for (int i = 1; i <= n; ++i) {
        int a; scanf("%d", &a);
        r = __gcd(r, a);
        for (int p : g[a])
            c[p]++;
    }

    int m = 0;
    for (int p : ps) m = max(m, c[p]);

    if (m <= 1) printf("pairwise coprime\n");
    else if (r == 1) printf("setwise coprime\n");
    else printf("not coprime\n");

    return 0;
}