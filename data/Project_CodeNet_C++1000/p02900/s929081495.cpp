#include <bits/stdc++.h>
#define N 1000099
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define LL long long
using namespace std;
int n;
LL a, b;
LL gcd(LL x, LL y)
{
    if (y == 0) return x;
    return gcd(y, x % y);
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
    cout << cal(gcd(a, b)) << endl;
    return 0;
}
