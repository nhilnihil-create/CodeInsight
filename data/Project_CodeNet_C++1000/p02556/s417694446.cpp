#include<bits/stdc++.h>
#define ll long long
#define mx 200009
#define pb push_back
using namespace std;
void f(int n)
{
   int x[mx],y[mx],ans;
   vector<int>a;
   vector<int>b;
   for(int i=1;i<=n;i++)
   {
      scanf("%d%d",&x[i],&y[i]);
      a.pb(x[i]+y[i]);
      b.pb(x[i]-y[i]);
   }
   sort(a.begin(),a.end());
   sort(b.begin(),b.end());
   int ans1=a[a.size()-1]-a[0];
   int ans2=b[b.size()-1]-b[0];
   ans=max(ans1,ans2);
   printf("%d\n",ans);
}
int main()
{
      int n;
      while(scanf("%d",&n)!=EOF)
      {
         f(n);
      }
      return 0;
}
