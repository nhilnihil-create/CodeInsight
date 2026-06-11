#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
int a[maxn];
int b[maxn];
int n;
ll ans=0;
struct node
{
    int id;
    int sum;
    bool operator<(const node &t) const{
     return sum<t.sum;
    }
};
priority_queue<node>que;
int slove( node no)
{
    int ids=no.id;
    int t1=ids+1;
    int t2=ids-1;
    if(t2==0)
        t2=n;
    if(t1==n+1)
        t1=1;
  int  sum=b[t1]+b[t2];
   if(sum+a[ids]>b[ids])
    return 0;
   ans=ans+(ll)(no.sum-a[ids])/sum;
   no.sum=(no.sum-a[ids])%sum+a[ids];
   b[ids]=no.sum;
   if(no.sum>a[ids])
   {
       que.push(no);
   }
   else if(no.sum<a[ids])
    return 0;
else
    return 1;
}
int main()
{
     scanf("%d",&n);
     for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
     for(int i=1;i<=n;i++){
        scanf("%d",&b[i]);
       if(a[i]!=b[i])
       que.push({i,b[i]});
     }
        int flag;
        while(!que.empty())
        {

            if(que.top().sum>a[que.top().id])
            {

                flag=slove(que.top());
                que.pop();
                if(flag==0)
                {
                    puts("-1");
                    return 0;
                }
            }
            else
            {
                 puts("-1");
                  return 0;
            }
        }
        printf("%lld\n",ans);

    return 0;
}
