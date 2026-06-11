#include<iostream>
using namespace std;
int main (void)
{
  int a,b,c,d,aa,bb;
  cin>>a>>b>>c>>d;
  aa=a/d;
  bb=c/b;
 // cout<<aa<<" "<<bb<<endl;
  if(a%d!=0){aa++;}
  if(c%b!=0){bb++;}
  if(aa>=bb){cout<<"Yes";}
  else cout<<"No";

}