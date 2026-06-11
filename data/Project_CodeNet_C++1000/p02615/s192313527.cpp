#include<bits/stdc++.h>
using namespace std;
int a[200005],n;
long long ans;
bool cmp(int s1,int s2)
{
return s1>s2;
}
int main()
{
cin>>n;
for(int i=1;i<=n;i++)cin>>a[i];
sort(a+1,a+n+1,cmp);
//for(int i=1;i<=n;i++)cout<<a[i]<<" ";cout<<endl;
ans=a[1];
for(int i=3;i<=n;i++)ans+=a[(i+1)/2];
cout<<ans<<endl;	
return 0;
}