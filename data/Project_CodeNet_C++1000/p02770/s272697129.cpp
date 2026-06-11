#include <cstdio>
#include <iostream>
#include <cassert>
#include <string>
#include <algorithm>
#include <cstring>
#include <utility>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <cmath>
#include <deque>
#include <unordered_map>
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
const int MAXN = 5678;
LL d[MAXN], td[MAXN];

int main() {
    int K, Q;
    scanf("%d %d", &K, &Q);
    for (int i = 0; i < K; i++)
        scanf("%lld", &d[i]);
    for (int i = 0; i < Q; i++) {
        LL n, x, m;
        scanf("%lld %lld %lld", &n, &x, &m);
        x %= m;
        LL tsum = 0;
        LL zsum = 0;
        for (int i = 0; i < K; i++) {
            td[i] = (d[i] % m);
            if (!td[i]) zsum++;
            tsum += td[i];
        }
        LL sum = tsum * ((n - 1) / K) + x;
        LL zcnt = zsum * ((n - 1) / K);
        for (int i = 0; i < ((n - 1) % K); i++) {
            sum += td[i];
            if (!td[i]) zcnt++;
        }
        printf("%lld\n", n - 1 - sum / m - zcnt);
    }
    return 0;
}
