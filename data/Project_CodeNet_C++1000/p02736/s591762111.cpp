#include<bits/stdc++.h>
using namespace std;
int main()
{
  int N;
  string M;
  bool a=false,b=false,c=false;
  cin>>N>>M;
  for(int i=0;i<N;i++)
  {
    a|=M.at(i)=='2';
    b^=M.at(i)=='2'&&((N-1)&i)==i;
    c^=M.at(i)=='3'&&((N-1)&i)==i;
  }
  if(b)
    return cout<<1<<endl,0;
  if(a)
    return cout<<0<<endl,0;
  if(c)
    return cout<<2<<endl,0;
  else
    return cout<<0<<endl,0;
}