#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, m, v, w;
vector<int> a, p;

bool chk(int x){
        if (x + w >= n) return true;
        int r = v - w - x;
        if (r < 0) {
            for (int i = x + 1; i + w <= n; ++i)
                if (a[p[x]] + m < a[p[i]]) return false;
            return true;
        }
        else {
            ll s = 1ll * r * m;
            for (int i = x + 1; i + w <= n; ++i) {
                int y = a[p[x]] + m - a[p[i]];
                if (y > 0)
                    s -= a[p[x]] + m - a[p[i]];
                else if (y < 0)
                    return false;
            }
            return s <= 0;
        }
    }

int main(void) {
    scanf("%d%d%d%d", &n, &m, &v, &w);
    a.resize(n, 0);
    p.resize(n, 0);
    for (int& i : a) scanf("%d", &i);
    iota(p.begin(), p.end(), 0);
    sort(p.begin(), p.end(), [&](int i, int j) { return a[i] < a[j]; });

    int l = 0, r = n - 1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (chk(mid)) r = mid - 1;
        else l = mid + 1;
    }


    printf("%d\n", n - l);
    return 0;
}