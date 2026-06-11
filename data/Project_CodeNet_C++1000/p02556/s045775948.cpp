#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
struct node
{
    int x;
    int y;
    int v1;
    int v2;
}a[200100];
bool cmp1(node a,node b)
{
    return a.v1<b.v1;
}
bool cmp2(node a,node b)
{
    return a.v2<b.v2;
}
void solve(int T)
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d %d",&a[i].x,&a[i].y);
        a[i].v1=a[i].x-a[i].y;
        a[i].v2=a[i].x+a[i].y;
    }
    sort(a+1,a+n+1,cmp1);
    int ans=abs(a[1].v1-a[n].v1);
    sort(a+1,a+n+1,cmp2);
    ans = max(ans,abs(a[1].v2-a[n].v2));
    cout << ans;
}



signed main()
{
    int t=1;
    //scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        solve(i);
    }
    return 0;
}