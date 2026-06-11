#include "bits/stdc++.h"
using namespace std;
int my_re(int64_t x)
{
  if(x%26==0)
    return 26;
  else
    return x%26;
}
int main()
{
  int64_t n,p;
  cin>>n;
  p=n;
  vector<int64_t> a;
  while(p!=0)
  {
    a.push_back(my_re(p));
    p=(p-my_re(p))/26;
  }
  reverse(a.begin(),a.end());
  for(int i=0;i<a.size();i++)
  {
    a.at(i)+=96;
    cout<<(char)a.at(i);
  }
}