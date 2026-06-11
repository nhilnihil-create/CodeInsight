#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int n, a[maxn], b[maxn];
long long ans;
priority_queue<pair<int, int>, vector<pair<int, int> >,
    greater<pair<int, int> > > q;

bool chk(int i) {
    return b[i] - b[(i - 1 + n) % n] - b[(i + 1) % n] >= a[i];
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }
    for (int i = 0; i < n; i++) {
        if (chk(i)) q.push({b[i], i});
    }
    while (!q.empty()) {
        int i = q.top().second; q.pop();
        int t = b[(i - 1 + n) % n] + b[(i + 1) % n];
        ans += (b[i] - a[i]) / t;
        b[i] -= (b[i] - a[i]) / t * t;
        i = (i - 1 + n) % n;
        if (chk(i)) q.push({b[i], i});
        i = (i + 2 + n) % n;
        if (chk(i)) q.push({b[i], i});
    }
    for (int i = 0; i < n; i++) {
        if (a[i] ^ b[i]) printf("-1\n"), exit(0);
    }
    printf("%lld\n", ans);
    return 0;
}