#include <bits/stdc++.h>

#define F first 
#define S second
#define PB push_back
#define ALL(x) x.begin(), x.end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef priority_queue<int> HEAP;
typedef priority_queue<int, vector<int>, greater<int> > RHEAP;

const int N = 200010, M = 1010;

int n, d, a;
LL s[N];
PII mon[N];

int main()
{
    scanf("%d%d%d", &n, &d, &a);
    for (int i = 1; i <= n; i ++ ) 
    {
        int x, h;
        scanf("%d%d", &x, &h);
        mon[i] = {x, h};
    }
    sort(mon + 1, mon + 1 + n);

    LL res = 0;
    for (int i = 1, j = 1; i <= n; i ++ )
    {
        s[i] += s[i - 1];
        mon[i].S -= s[i];

        if (mon[i].S <= 0) continue;
        
        while (j <= n && mon[j].F - mon[i].F <= 2 * d) j ++ ;

        LL cnt = max(0LL, (LL)(mon[i].S + a - 1LL) / a);
        s[i] += cnt * (LL)a;
        s[j] -= cnt * (LL)a;
        res += cnt;
    }
    printf("%lld\n", res);
    return 0;
}
