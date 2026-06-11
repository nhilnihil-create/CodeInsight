#include <bits/stdc++.h>
using namespace std;
int main()
{
  long long i,j,k,a,b,c=0,n;
  cin>>a>>b;
  if(a==1 ) c+=300000;
  else if(a==2) c+=200000;
  else if(a==3) c+=100000;
  if(b==1 ) c+=300000;
  else if(b==2) c+=200000;
  else if(b==3) c+=100000;
  if(a==1 && b==1) cout<<"1000000"<<endl;
  else cout<<c<<endl;
return 0;
}
