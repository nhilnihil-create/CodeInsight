/*** keep hungry and calm CoolGuang!***/
#include <bits/stdc++.h>
#include<algorithm>
#include<stdio.h>
#pragma GCC optimize(2)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll INF=1e13;
const ll maxn=1e6+5;
const int mod=998244353;
const double eps=1e-12;
ll n,m,p;
ll num[maxn];
int pre[maxn][2];
int cur[maxn][2];
ll st[maxn][30];
ll lg[maxn];
void work()
{
    ll cnt=0;
    for(int i=1;i<=n;i++)
        lg[i]=lg[i/2]+1;
    for(int i=1;i<=n;i++)
        st[i][0]=num[i];
    for(int j=1;j<=25;j++)
        for(int i=1;i+(1<<j)-1<=n;i++)
            st[i][j]=max(st[i][j-1],st[i+(1<<(j-1))][j-1]);
}
ll query(ll x,ll y)
{
    ll len=lg[y-x+1]-1;
    return max(st[x][len],st[y-(1<<len)+1][len]);//为啥+1
}
void work_one(){//预处理左边第一个比他大的
    for(int i=1;i<=n;i++){
        pre[i][1]=pre[i][0]=0;//假设第一个比他大的和第二个比他大的都木有
        ll l=1,r=i-1;
        ll ans=-1,aim=num[i];
        while(l<=r){
            ll mid=(l+r)/2;
            if(query(mid,i)>aim){
                l=mid+1;
                ans=mid;
            }
            else r=mid-1;
        }
       // printf("%lld\n",ans);
        if(ans==-1) continue;
        pre[i][0]=ans;
        ll temp=-1;
        l=1,r=ans-1;
        while(l<=r){
            ll mid=(l+r)/2;
            if(query(mid,ans-1)>aim){
                l=mid+1;
                temp=mid;
            }
            else r=mid-1;
        }
        if(temp==-1) continue;
        pre[i][1]=temp;
    }
}
void work_two(){
    for(int i=n;i>=1;i--){
        cur[i][1]=cur[i][0]=n+1;
        ll l=i+1,r=n;
        ll ans=-1,aim=num[i];
        while(l<=r){
            ll mid=(l+r)/2;
            if(query(i,mid)>aim){
                r=mid-1;
                ans=mid;
            }
            else l=mid+1;
        }
       // printf("%lld\n",ans);
        if(ans==-1) continue;
        cur[i][0]=ans;
        ll temp=-1;
        l=ans+1,r=n;
        while(l<=r){
            ll mid=(l+r)/2;
            if(query(ans+1,mid)>aim){
                r=mid-1;
                temp=mid;
            }
            else l=mid+1;
        }
        if(temp==-1) continue;
        cur[i][1]=temp;
    }
}
int main()
{
    scanf("%lld",&n);
    for(int i=1;i<=n;i++) scanf("%lld",&num[i]);
    work();
    work_one();
    work_two();
    ll ans=0;
    for(int i=1;i<=n;i++){
        ans+=(pre[i][0]-pre[i][1])*(cur[i][0]-i)*num[i];
        ans+=(cur[i][1]-cur[i][0])*(i-pre[i][0])*num[i];
    }
    printf("%lld\n",ans);
    return 0;
}
/***
5
1 2 3
2 2 3
3 1 2
2 1 2
1 1 2
***/
