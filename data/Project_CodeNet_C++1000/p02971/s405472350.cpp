#include"bits/stdc++.h"
#define sz(a) (int)a.size()
using namespace std;
int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0); 
  int n; cin>>n; vector<int>a(n),v1(n),v2(n); for(int i=0;i<=n-1;i++){ cin>>a[i]; }
  v1[0]=a[0]; v2[n-1]=a[n-1]; for(int i=1;i<=n-1;i++) v1[i]=max(a[i],v1[i-1]); for(int i=n-2;i>=0;i--) v2[i]=max(v2[i+1],a[i]); 
  for(int i=0;i<=n-1;i++)
  {
    if(i==0) { cout<<v2[1]<<"\n";}
    else if(i==n-1){ cout<<v1[n-2]<<"\n"; }
    else cout<<max(v1[i-1],v2[i+1])<<"\n"; 
  }  
  return 0;
}