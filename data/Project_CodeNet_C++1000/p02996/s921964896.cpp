#include "bits/stdc++.h"
using namespace std;

int main()
{
  int n;
  cin>>n;
  int64_t time=0;
  string ans="Yes";
  vector<pair<int64_t,int64_t>> t(n);
  for(int i=0;i<n;i++)
  {
    cin>>t.at(i).second>>t.at(i).first;
  }
  sort(t.begin(),t.end());
  for(int i=0;i<n;i++)
  {
    time+=t.at(i).second;
    if(t.at(i).first<time)
    {
      ans="No";
      break;
    }
  }
  cout<<ans<<endl;
}