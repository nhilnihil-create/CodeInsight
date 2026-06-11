#include "bits/stdc++.h"
using namespace std;

int main()
{
  int n;
  cin>>n;
  vector<int> m(n-1);
  vector<int> ans(n,0);
  for(int i=0;i<n-1;i++)
  {
    cin>>m.at(i);
    ans.at(m.at(i)-1)++;
  }
  for(int i=0;i<n;i++)
  {
    cout<<ans.at(i)<<endl;
  }
}