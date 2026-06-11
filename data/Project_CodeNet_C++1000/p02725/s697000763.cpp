#include "bits/stdc++.h"
using namespace std;

int main()
{
  int k,n,m;
  cin>>k>>n;
  m=0;
  vector<int> a(n);
  for(int i=0;i<n;i++)
  {
    cin>>a.at(i);
  }
  for(int i=0;i<n-1;i++)
  {
    m=max(m,(a.at(i+1)-a.at(i)));
  }
  m=max(m,(k-a.at(n-1)+a.at(0)));
  cout<<k-m<<endl;
}