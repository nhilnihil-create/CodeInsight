#include <iostream>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

const int N = 2e5 + 10;

PII m[N];
LL diff[N];

bool cmp(PII a, PII b)
{
    return a.first < b.first;
}

int locate(LL x, int left, int right)
{
    int l = left, r = right;
    while (l < r) {
        int mid = l + r + 1 >> 1;
        if (m[mid].first <= x)
            l = mid;
        else
            r = mid - 1;
    }
    return l;
}

int main()
{
    int n, d, a;
    LL res = 0;
    scanf("%d%d%d", &n, &d, &a);
    for (int i = 1; i <= n; ++i) {
        int x, h;
        scanf("%d%d", &x, &h);
        m[i] = {x, h};
    }
    
    sort(m + 1, m + n + 1, cmp);
    
    for (int i = 1; i <= n; ++i) {
        diff[i] += diff[i - 1];
        m[i].second -= diff[i];
        if (m[i].second <= 0)
            continue;
        LL cnt = m[i].second / a;
        if (m[i].second % a)
            cnt++;
        res += cnt;
        LL k = (LL)m[i].first + d * 2;
        diff[i] += a * cnt;
        diff[locate(k, i, n) + 1] -= a * cnt;
    }
    
    printf("%lld\n", res);
    return 0;
}