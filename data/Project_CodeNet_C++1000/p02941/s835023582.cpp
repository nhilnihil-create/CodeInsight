#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define N 200005

int n;
ll a[N], b[N];

typedef pair <ll, int> pli;

priority_queue <pli> pq;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i ++) scanf("%lld", &a[i]);
    for (int i = 0; i < n; i ++) {
		scanf("%lld", &b[i]);
        pq.push(pli(b[i], i));
    }
    ll ans = 0;
    while (!pq.empty()) {
        pli rpt = pq.top(); pq.pop();
        int id = rpt.second;
		if (rpt.first == a[id]) continue;
        ll sum = b[(id+n-1)%n] + b[(id+1)%n];
        ll mx = max(b[(id+n-1)%n], b[(id+1)%n]);
        mx = max(mx, a[id]);
        ll t = (b[id] - mx + sum - 1) / sum;
        b[id] -= sum * t;
        ans += t;
        if (b[id] < a[id]) {
            puts("-1");
            return 0;
        }
        pq.push(pli(b[id], id));
    }
    for (int i = 1; i <= n; i ++) if (b[i] != a[i]) {
        puts("-1");
        return 0;
    }
    printf("%lld\n", ans);
    return 0;
}
