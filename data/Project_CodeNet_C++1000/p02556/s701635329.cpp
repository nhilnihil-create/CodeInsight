#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  cin>>n;
  vector<pair<int,int>>a(n);
  for(int i=0;i<n;i++)cin>>a[i].first>>a[i].second;
  
  vector<long long> s(n),d(n);
  for(int i=0;i<n;i++)
  {
    s[i]=a[i].first+a[i].second;
    d[i]=a[i].first-a[i].second;
  }
  sort(s.begin(),s.end());
  sort(d.begin(),d.end());
  long long ans=max((s[n-1]-s[0]),abs(d[n-1]-d[0]));
  cout<<ans<<endl;
  return 0;
}
  