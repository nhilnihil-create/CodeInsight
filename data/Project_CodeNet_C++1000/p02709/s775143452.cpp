#include<iostream>
#include<cstdio>
#include <stdio.h>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<queue>
#include<map>
#include<vector>
#include <set>
#define ll long long
#define IO ios::sync_with_stdio(false);cin.tie();cout.tie(0)
#define inf 0x3f3f3f3f
#define pi 3.1415926535898
using namespace std;
const ll mod = 1e9+7;
ll n;
ll dp[2020][2020];
struct A
{
    ll  num,avl;
} a[5005];
int cmp(A a,A b)
{
    return a.avl>b.avl;
}
ll work(ll l,ll r,ll now)
{
    if(l>r)
        return a[now].avl;
    if(dp[l][r]!=-1)
        return dp[l][r];
    ll fist=work(l,r-1,now+1)+a[now].avl*abs(a[now].num-r);
    ll second=work(l+1,r,now+1)+a[now].avl*abs(a[now].num-l);
    dp[l][r]=max(dp[l][r],max(fist,second));
    return dp[l][r];
}
int main()
{
    cin>>n;
    memset(dp,-1,sizeof(dp));
    for(int i=1; i<=n; i++)
    {
        cin>>a[i].avl;
        a[i].num=i;
    }
    sort(a+1,a+n+1,cmp);
    cout<<work(1,n,1)<<endl;
    return 0;
}
