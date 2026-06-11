#include<bits/stdc++.h>
#define int long long
using namespace std;
struct abcd{int x,h;}b[200001];
bool cmp(abcd i,abcd j){return i.x<j.x;}
int n,d,a,qn[200001],qx[200001],q1,q2,qs,ans;
signed main()
{
 scanf("%lld%lld%lld",&n,&d,&a);
 for(int i=1;i<=n;i++)
 {
  scanf("%lld%lld",&b[i].x,&b[i].h);
  b[i].h=(b[i].h-1)/a+1;
 }
 sort(b+1,b+n+1,cmp);
 for(int i=1;i<=n;i++)
 {
  while(qx[q1]<b[i].x&&q1<q2)qs-=qn[q1++];
  if(b[i].h>qs)
  {
   ans+=(qn[q2]=b[i].h-qs);
   qx[q2++]=b[i].x+2*d;
   qs=b[i].h;
  }
 }
 printf("%lld",ans);
 return 0;
}