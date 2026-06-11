#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1e5;
int pre[N+2];
int post[N+2];
int p[N+2];
int loc[N+2];
int main()
{
    memset(pre,-1,sizeof pre);
    memset(post,-1,sizeof post);
    int n; cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> p[i];
        loc[p[i]] = i;
    }

    set<int> available;
    available.insert(0);
    available.insert(n+1);

    LL ans = 0;
    for(LL k = n; k >= 1; k--)
    {
        LL aft = *available.upper_bound(loc[k]);
        LL bef = *(--available.upper_bound(loc[k]));

        post[bef] = loc[k];
        pre[aft] = loc[k];
        pre[loc[k]] = bef;
        post[loc[k]] = aft;

        if(bef >= 1)
            ans += k*(bef-pre[bef])*(aft-loc[k]);
        if(aft <= n)
            ans += k*(loc[k]-bef)*(post[aft]-aft);
        
        available.insert(loc[k]);
    }
    cout<<ans<<endl;

    return 0;
}