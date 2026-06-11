#include<bits/stdc++.h>
using namespace std;
int main()
{
  int a=0,b=1,temp,x;
  char N;
  while(cin>>N){x=N-'0';temp=a;a=min(a+x,b+10-x);b=min(temp+x+1,b+9-x);}
  return cout<<a<<endl,0;
}