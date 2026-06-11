#include <bits/stdc++.h>
#define fi first 
#define se second
using namespace std;
typedef long long i64;
typedef pair<int, int> pii;
const int N = 2e5+5;
int n, a[N], b[N]; i64 ans; priority_queue<pii> q;
int get(int x) { return !x?n:x==n+1?1:x; }
int main()
{ 
    scanf("%d", &n); for(int i = 1; i <= n; ++i) scanf("%d", a+i);
    for(int i = 1; i <= n; ++i) scanf("%d", b+i);
    for(int i = 1; i <= n; ++i) 
        if(a[i] > b[i]) return puts("-1"), 0;
        else if(a[i] < b[i]) q.push(pii(b[i], i));
    while(q.size())
    {
        pii u = q.top(); q.pop();
        int i = u.se, d = b[i]-a[i], w = b[get(i-1)]+b[get(i+1)];
        if(d/w == 0&&a[i] != b[i]) return puts("-1"), 0;
        ans += d/w, b[i] -= d/w*w;
        if(a[i] < b[i]) q.push(pii(b[i], i));
    }
    printf("%lld\n", ans);
    return 0;
}