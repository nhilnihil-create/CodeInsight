#include <bits/stdc++.h>
using namespace std;
#define MAXNUM 222111
#define rep(i,s,t) for(int i=s;i<t;i++)
#define pii pair<int,int>
typedef long long ll;
int a[MAXNUM],b[MAXNUM];
int main()
{
    int n;scanf("%d",&n);
    rep(i,1,n+1)scanf("%d",&a[i]);
    priority_queue<pii> pq;
    rep(i,1,n+1){
        scanf("%d",&b[i]);
        if(b[i]!=a[i])
            pq.emplace(b[i],i);
    }
    ll res=0;
    while(!pq.empty())
    {
        pii p=pq.top();pq.pop();
        int sum=(b[p.second%n+1]+b[(p.second-2+n)%n+1]),num=max(b[p.second%n+1],b[(p.second-2+n)%n+1]);
        num=max(num,a[p.second]);
        int k=max(1,(b[p.second]-num)/sum);
        b[p.second]-=k*sum,res+=k;
        if(b[p.second]<a[p.second]){res=-1;break;}
        else if(b[p.second]>a[p.second])
            pq.emplace(b[p.second],p.second);
    }
    printf("%lld\n",res);
}