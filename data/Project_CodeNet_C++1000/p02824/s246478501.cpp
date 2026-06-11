/*
 * @Author: RBQRBQ
 * @Date: 2020-04-02 17:25:22
 * @LastEditors: RBQRBQ
 * @LastEditTime: 2020-04-02 21:01:12
 */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> VI;
typedef pair<int,int> pii;
namespace IO{
    template<typename T>inline void read(T &x){
        x=0;ll f=1;char ch=getchar();
        while(!isdigit(ch)){if(ch=='-')f=-f;ch=getchar();}
        while(isdigit(ch)){x=x*10+ch-48;ch=getchar();}
        x=x*f;
    }
}
using namespace IO;
ll a[100000+10];
ll n,m,v,p;
bool cmp(ll a,ll b)
{
    return (a>b);
}
bool judge(ll x)
{
    if(x<=p) return true;
    if(a[x]+m<a[p]) return false;
    if(p-1+n-x>=v) return true;
    ll sum=(p)*m+(n-x)*m;
    for(int i=p;i<=x-1;i++)
    sum+=a[x]+m-a[i];
    if(sum<m*v) return false;
    else return true;
}
int main()
{
    read(n),read(m),read(v),read(p);
    for(int i=1;i<=n;i++)
    {
        read(a[i]);
    }
    sort(a+1,a+n+1,cmp);
    ll l=0,r=n;
    while(l<r)
    {
        ll mid=(l+r+1)/2;
        if(judge(mid)) l=mid;
        else r=mid-1;
    }
    cout<<l;
}