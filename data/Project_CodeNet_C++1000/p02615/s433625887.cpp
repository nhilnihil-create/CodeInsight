#include <bits/stdc++.h>
using namespace std;

const int N = 500001;
int a[N];
typedef long long ll;

int main(void) {
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);
    typedef pair<int, int> pii;
    priority_queue<pii> q;
    q.push({ a[n - 1], a[n] });
    q.push({ a[n - 1], a[n] });
    ll sum = a[n];
    for (int i = n - 2; i >= 1; --i) {
        pii p = q.top(); q.pop();
        sum += p.first;
        q.push({ a[i], p.first });
        q.push({ a[i], p.second });
    }
    printf("%lld\n", sum);
    return 0;
}