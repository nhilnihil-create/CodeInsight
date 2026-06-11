#include <bits/stdc++.h>
 
using namespace std;
 
pair <long long, long long> a[200005];
 
int main() {
    int n, d, aa;
    scanf("%d%d%d", &n, &d, &aa);
 
    for (int i = 0; i < n; i++) scanf("%lld%lld", &a[i].first, &a[i].second);
 
    sort(a, a + n);
 
    queue <pair<long long, long long>> que;
    long long sum = 0;
    long long res = 0;
 
    for (int i = 0; i < n; i++) {
        while (que.size() && que.front().first < a[i].first) {
            sum -= que.front().second;
            que.pop();
        }
 
        if (a[i].second - sum <= 0) continue;
 
        long long need = (a[i].second - sum + aa - 1) / aa;
        res += need;
        que.push(make_pair(a[i].first + 2 * d, need * aa));
        sum += need * aa;
    }
 
    printf("%lld\n", res);
}