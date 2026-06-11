#include<bits/stdc++.h>
using namespace std;

int main()
{
 int k;
 cin>>k;
  string S =  "ACL";
  string R;
  for(int i=1;i<=k;i++)
  {
    R = R + S;
  }
  cout<<R<<endl;
  return 0;
}