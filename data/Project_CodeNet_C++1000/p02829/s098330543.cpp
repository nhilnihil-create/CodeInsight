#include<bits/stdc++.h>
using namespace std;
int main()
{
  int a,b;
  set<int>s;
  cin>>a>>b;
  s.insert(a);
  s.insert(b);
  if(s.count(1)==0)
    cout<<"1"<<endl;
  else if(s.count(2)==0)
    cout<<"2"<<endl;
  else
    cout<<"3"<<endl;
}