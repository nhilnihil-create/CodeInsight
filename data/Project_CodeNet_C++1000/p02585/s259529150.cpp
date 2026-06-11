#include <bits/stdc++.h>

using namespace std;

int n, k;
int a[5010], p[5010];
int vis[5010];
long long sum;
vector<long long> pre;

int main()
{
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; ++i)
        scanf("%d", &p[i]);
    for(int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);

    long long ans = -1e18;
    
    for(int i = 1; i <= n; ++i)
    {
        memset(vis, 0, sizeof(vis));
        pre.clear();
        int st = i;

        sum = 0;
        while(!vis[st])
        {
            vis[st] = 1;
            pre.push_back(sum += a[st]);
            st = p[st];
        }

        int len = pre.size();
        int t = k/len, m = k%len;
        for(int i = 2; i < len; ++i)
            pre[i] = max(pre[i], pre[i-1]);

        if(t >= 1)
        {
            ans = max(ans, pre[len-1]-pre[0]);
            ans = max(ans, pre[m]-pre[0]+t*sum);
            ans = max(ans, pre[len-1]-pre[0]+(t-1)*sum);
        }else{
            ans = max(ans, pre[m]-pre[0]);
        }

    }
    printf("%lld\n", ans);

}