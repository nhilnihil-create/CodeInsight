#include <bits/stdc++.h>
using namespace std;

const int N=2005;
typedef long long ll;
struct node
{
    ll x;
    int pos;
}d[N];
ll dp[N][N];
int n;

bool cmp(node a,node b)
{
    return a.x>b.x;
}
ll f(int l,int r)
{
    if(l>r) return 0;
    if(dp[l][r]) return dp[l][r];
    int i=l+n-1-r;
    dp[l][r]=max(f(l+1,r)+d[i].x*abs(d[i].pos-l),f(l,r-1)+d[i].x*abs(d[i].pos-r));
    return dp[l][r];
}

int main()
{
    scanf("%d",&n);
    for (int i=0;i<n;i++)
    {
        scanf("%lld",&d[i].x);
        d[i].pos=i;
    }
    sort(d,d+n,cmp);
    printf("%lld\n",f(0,n-1));
    return 0;
}
