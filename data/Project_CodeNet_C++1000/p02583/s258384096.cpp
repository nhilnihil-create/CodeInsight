#include<bits/stdc++.h>
using namespace std;
#define ll long long 

int main()
{
 int n,ans=0;
  cin>>n;
  ll a[n];
  for(auto& i:a) cin>>i;
  sort(a,a+n);
  
  for(int i=0;i<n;i++)
    for(int j=i+1;j<n;j++)
       for(int k=j+1;k<n;k++)
       { if(a[i]!=a[j] && a[j]!=a[k])
       { if(a[i]+a[j]>a[k]) ans++;
       }
       }
  cout<<ans;
}