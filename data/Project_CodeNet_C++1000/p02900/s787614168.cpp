#include <bits/stdc++.h>
#define N 1000099
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define LL long long
using namespace std;
int n, cnt;
LL a, b;
bool is[N];
LL prime[N];
LL gcd(LL x, LL y)
{
    if (y == 0) return x;
    return gcd(y, x % y);
}
void getprime()
{
    is[1] = is[0] = 1;
    prime[0] = 1;
    for (int i = 2; i < N; i++)
    {
        if (!is[i]) prime[++cnt] = i;
        for (int j = 1; j <= cnt && prime[j] * i < N; j++)
        {
            is[prime[j] * i] = 1;
            if (i % prime[j] == 0) break;
        }
    }
}
bool check(LL x)
{
    for (LL i = 2; i * i <= x; i++)
    {
        if (x % i == 0) return 0;
    }
    return 1;
}
int cal(LL x)
{
    int res = 0;
    for (LL i = 1; i * i <= x; i++)
    {
        if (x % i == 0)
        {
            if (check(i)) res++;
            if (x / i != i && check(x / i)) res++;
        }
    }
    return res;
}
int main()
{
    cin >> a >> b;
    getprime();
    cout << cal(gcd(a, b)) << endl;
    return 0;
}
