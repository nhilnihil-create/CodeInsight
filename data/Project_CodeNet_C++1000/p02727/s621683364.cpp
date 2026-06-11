#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const int maxn = 100010;

int x, y, a, b, c;
int p[maxn], q[maxn], r[maxn];

int main() {
    ll ans = 0;
    scanf("%d%d%d%d%d", &x, &y, &a, &b, &c);
    vector<int> ap;
    for (int i = 0; i < a; i++) {
        scanf("%d", &p[i]);
    }
    for (int i = 0; i < b; i++) {
        scanf("%d", &q[i]);
    }
    for (int i = 0; i < c; i++) {
        scanf("%d", &r[i]);
    }
    sort(p, p + a, greater<int>());
    sort(q, q + b, greater<int>());
    sort(r, r + c, greater<int>());
    for (int i = 0; i < x; i++) {
        ap.push_back(p[i]);
    }
    for (int i = 0; i < y; i++) {
        ap.push_back(q[i]);
    }
    sort(ap.begin(), ap.end());
    for (int i = 0; i < c && i < ap.size(); i++) {
        if (ap[i] < r[i]) ap[i] = r[i];
    }
    for (int it : ap) {
        ans += (ll)it;
    }
    printf("%lld", ans);
    return 0;
}