#include <bits/stdc++.h>
#define pb(x) push_back(x)
using namespace std;
typedef long long i64;
const int N = 5e5+5;
int n, d[N], v[N], q[N], l, r; char s[N]; i64 ans; vector<int> e[N];
int main()
{
    scanf("%s", s+1), n = strlen(s+1)+1, l = 1;
    for(int i = 1; i < n; ++i) 
        if(s[i] == '<') e[i].pb(i+1), ++d[i+1];
        else e[i+1].pb(i), ++d[i];
    for(int i = 1; i <= n; ++i) if(!d[i]) q[++r] = i;
    while(l <= r) 
    {
        int x = q[l++];
        for(int y:e[x]) 
        {
            v[y] = max(v[y], v[x]+1);
            if(--d[y] == 0) q[++r] = y;
        }
    }
    for(int i = 1; i <= n; ++i) ans += v[i]; printf("%lld\n", ans);
    return 0;
}
