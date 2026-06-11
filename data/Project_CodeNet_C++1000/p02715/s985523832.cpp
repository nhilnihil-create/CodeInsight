#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 1000000007;
const int Maxn = 100005;

int n, k;
int cnt[Maxn];
int res;

int toPower(int a, int p)
{
    int res = 1;
    while (p) {
        if (p & 1) res = ll(res) * a % mod;
        p >>= 1; a = ll(a) * a % mod;
    }
    return res;
}

int main()
{
    scanf("%d %d", &n, &k);
    for (int i = k; i > 0; i--) {
        cnt[i] = toPower(k / i, n);
        for (int j = i + i; j <= k; j += i)
            cnt[i] = (cnt[i] - cnt[j] + mod) % mod;
        res = (res + ll(cnt[i]) * i) % mod;
    }
    printf("%d\n", res);
    return 0;
}
