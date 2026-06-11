#include <algorithm>
#include <iostream>
#include <cstdio>
typedef long long ll;
const int maxn = 1e5 + 7;

inline ll get(const int &l,const int &r)
{
    extern ll sum[];
    return sum[r] - sum[l - 1]; 
}//get sum

ll n, m, v, p;
ll a[maxn], sum[maxn];
ll res;

int main(void)
{
    scanf("%lld %lld %lld %lld", &n, &m, &v, &p);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    std::sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++)
        sum[i] = sum[i - 1] + a[i];
    for (ll i = 1; i <= n - p; i++)
    {
        ll vote = m * v - m * (p - 1) - m; //总投票 - 投给前p - 1个 - 投给a[i]的 = 投给 < a[i] | a[i + 1] ~ a[p]
        ll had = a[i] + m; 
        if (had >= a[n - p + 1] && vote <= (i - 1) * m + had * (n - p + 1 - i) - get(i + 1, n - p + 1)) res++; // (i - 1) * m 投给 < a[i], 后半段投给a[i] ~ a[n - p + 1], 若 >= vote 则可能;
    }
    res += p; 
    std::cout << res << std::endl;
}