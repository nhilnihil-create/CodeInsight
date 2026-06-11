#include<bits/stdc++.h>
using namespace std;
int main()
{int a,b,c;
 cin>>a>>b>>c;
 int q[a],w[b],n,m,k;
 int ans=INT_MAX,a1=INT_MAX,a2=INT_MAX;
 for(int i=0;i<a;i++)cin>>q[i],a1=min(a1,q[i]);
 for(int i=0;i<b;i++)cin>>w[i],a2=min(a2,w[i]);
 while(c--)
 {
 cin>>n>>m>>k;
   ans=min(ans,(q[n-1]+w[m-1]-k));
 }cout<<min(ans,a1+a2);
  return 0;
}
