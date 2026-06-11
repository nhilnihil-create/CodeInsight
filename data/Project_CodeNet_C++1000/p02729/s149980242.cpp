#include<bits/stdc++.h>
using namespace std;
int main()
{
  long long a,b,k,i,c=0,d;
  cin>>a>>b;
  if(a>=2) c+=(a*(a-1))/2;
  if(b>=2) c+=(b*(b-1))/2;
  cout<<c<<endl;

}
