//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>

using namespace std;
const int N = 1e6 + 1;
int cnt[N];

void sieve()
{
    for (int i = 1; i < N; ++i)
    {
        for (int j = i; j < N; j += i)
            cnt[j]++;
    }
}

int main()
{
    //  freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    sieve();
    int n;
    scanf("%d", &n);
    long long ans = 0;
    for (int c = 1; c < n; ++c)
    {
        ans += cnt[n - c];
    }
    printf("%lld\n", ans);
}