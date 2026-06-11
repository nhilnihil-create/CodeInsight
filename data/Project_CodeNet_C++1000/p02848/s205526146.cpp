#include "bits/stdc++.h"
using namespace std;

int main()
{
  int n;
  string s;
  cin>>n>>s;
  vector<int> a(s.size());
  for(int i=0;i<s.size();i++)
  {
    a.at(i)=(int)s.at(i);
    a.at(i)+=n;
    if(a.at(i)>90)
      a.at(i)-=26;
    cout<<(char)a.at(i);
  }
}