#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[2005][2005];   // dp[i][j] 前 i 个人放了 j 个左边的
ll n,ma;
struct stu
{
    ll pos,w;
}a[2004];
bool cmp(stu u,stu v)
{
    return u.w<v.w;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i].w);
        a[i].pos=i;
    }
    sort(a+1,a+n+1,cmp);
    //for(int i=1;i<=n;i++) dp[i][i]=a[1].w*abs(a[1].pos-i);  // 枚举最小的挪到每一个位置
    for(int len=1;len<=n;len++)
    {
        for(int i=1;i+len-1<=n;i++)
        {
            int j=i+len-1;
            // 前 len 个数最大的为 a[len].w，枚举a[len]放的位置
            dp[i][j]=max(dp[i+1][j]+a[len].w*abs(a[len].pos-i),  // 放左边
                         dp[i][j-1]+a[len].w*abs(a[len].pos-j)); // 放右边
        }
    }
    cout<<dp[1][n];
    return 0;
}
