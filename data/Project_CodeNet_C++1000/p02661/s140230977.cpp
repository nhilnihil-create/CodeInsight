#include<bits/stdc++.h>
using namespace std;

int main()
{
  cout<<fixed<<setprecision(10);
  int n;
  cin>>n;
  vector<int>a(n);
  vector<int>b(n);
  
  for(int i=0;i<n;i++)
  {
    cin>>a[i]>>b[i];
  }
  sort(a.begin(),a.end());
  sort(b.begin(),b.end());
  int ans=0;
  if(n%2!=0)
  {
    ans=b[n/2]-a[n/2]+1;
  }
  else 
  {
    long long am=(a[(n/2)]+a[(n/2)-1]);
    long long bm=(b[(n/2)]+b[(n/2)-1]);
 	ans=(bm-am)+1;
  }
  cout<<ans<<endl;
 
  return 0;
}