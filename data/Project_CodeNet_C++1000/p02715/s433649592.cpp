#include <bits/stdc++.h>
using namespace std;
#define elif else if
typedef long long ll;
typedef unsigned long long ull;
#define DEBUG(x) cout << (x) << endl

#define MODULE 1000000007

int n, k;
int arr[200005] = {0};
int ans = 0;
map<int, int> record;
ll cnt[200005] = {0};

void dfs(int pos)
{
    if (pos == n)
    {
        int tmp = arr[0];
        for (int i = 1; i < n; i++)
        {
            tmp = __gcd(tmp, arr[i]);
        }
        ans += tmp;
        record[tmp] += 1;
        return;
    }
    for (int i = 1; i <= k; i++)
    {
        arr[pos] = i;
        dfs(pos + 1);
    }
}

void test_db()
{
    record.clear();
    ans = 0;
    dfs(0);
}

ll quick_pow(ll a, ll b)
{
    ll base = a;
    ll ans = 1;
    while (b)
    {
        if (b & 1)
        {
            ans *= base;
            ans %= MODULE;
        }
        base *= base;
        base %= MODULE;
        b >>= 1;
    }
    return ans % MODULE;
}

void solve()
{
    for (int i = k; i >= 1;i--)
    {
        cnt[i] = quick_pow(k / i, n);
        for (int j = 2; j * i <= k;j++)
        {
            cnt[i] -= cnt[j * i];
        }
        ll tmp = (cnt[i] * i) % MODULE;
        ans += tmp;
        ans %= MODULE;
        while(ans<0)
        {
            ans += MODULE;
        }
    }
}

int main()
{
    for (int _ = 0;_<=0; _++)
    {
        scanf("%d %d", &n, &k);
        // test_db();
        // printf("%d\n", ans);
        // for (map<int, int>::iterator it = record.begin(); it != record.end();it++)
        // {
        //     printf("%d:%d\n", it->first, it->second);
        // }
        solve();
        printf("%d\n", ans%MODULE);
    }
    return 0;
}
