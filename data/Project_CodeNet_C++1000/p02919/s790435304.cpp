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
struct node{
    int l,r;
    ll w;
}t[maxn<<2];
inline bool read(ll &num)
{
        char in;bool IsN=false;
        in=getchar();
        if(in==EOF) return false;
        while(in!='-'&&(in<'0'||in>'9')) in=getchar();
        if(in=='-'){ IsN=true;num=0;}
        else num=in-'0';
        while(in=getchar(),in>='0'&&in<='9'){
                num*=10,num+=in-'0';
        }
        if(IsN) num=-num;
        return true;
}
void build(int k,int l,int r){
    t[k].l=l;t[k].r=r;
    if(l==r){
        t[k].w=num[l];
        return;
    }
    int mid=(l+r)/2;
    build(k<<1,l,mid);
    build(k<<1|1,mid+1,r);
    t[k].w=max(t[k<<1].w,t[k<<1|1].w);
}
ll query(int k,int x,int y){
    if(t[k].l>=x&&t[k].r<=y){
        return t[k].w;
    }
    ll sum=0;
    int mid=(t[k].l+t[k].r)/2;
    if(x<=mid) sum=max(query(k<<1,x,y),sum);
    if(y>mid) sum=max(query(k<<1|1,x,y),sum);
    return sum;
}
void work_one(){//预处理左边第一个比他大的
    for(int i=1;i<=n;i++){
        pre[i][1]=pre[i][0]=0;//假设第一个比他大的和第二个比他大的都木有
        ll l=1,r=i-1;
        ll ans=-1,aim=num[i];
        while(l<=r){
            ll mid=(l+r)/2;
            if(query(1,mid,i)>aim){
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
            if(query(1,mid,ans-1)>aim){
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
            if(query(1,i,mid)>aim){
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
            if(query(1,ans+1,mid)>aim){
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
    for(int i=1;i<=n;i++)read(num[i]);
    build(1,1,n);
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
