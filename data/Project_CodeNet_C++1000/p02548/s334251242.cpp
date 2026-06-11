#include<bits/stdc++.h>
using namespace std;
int d[1000005];
int main()
{
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);

int n;
cin>>n;

memset(d,0,sizeof(d));

for(int i=1;i<=n;i++)
{
   for(int j=i;j<=n;j+=i)
   d[j]++;
}

int ans=0;


for(int i=1;i<n;i++)
{
  ans+=d[n-i];
}

cout<<ans<<endl;

return 0;
}

