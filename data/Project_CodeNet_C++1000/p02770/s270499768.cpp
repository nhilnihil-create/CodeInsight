// Problem : F - Modularness
// Contest : AtCoder Beginner Contest 156
// URL : https://atcoder.jp/contests/abc156/tasks/abc156_f
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <iostream>
using namespace std;
int d[5005],nd[5005];
long long ds[5005];
int main()
{
 int k,q;
 cin>>k>>q;
 for(int i=1;i<=k;i++)
  cin>>d[i];
 while(q--)
 {
  int n,x,m,cnt=0,ans;
  long long sum;
  cin>>n>>x>>m;
  ans=n-1;
  n--;
  for(int i=1;i<=k;i++)
  {
   nd[i]=d[i]%m;
   ds[i]=ds[i-1]+nd[i];
   cnt+=(nd[i]==0);
  }
  ans-=n/k*cnt;
  sum=x+n/k*ds[k]+ds[n%k];
  for(int i=1;i<=n%k;i++)
   ans-=(nd[i]==0);
  ans-=sum/m-x/m;
  cout<<ans<<endl;
 }
 return 0;
}