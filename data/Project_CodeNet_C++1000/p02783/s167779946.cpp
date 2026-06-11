#include<iostream>
#include<algorithm>
using namespace std;
int main (void)
{
  int h,a,ans;
 cin>>h>>a;
  ans=h/a;
  if(h%a!=0)ans++;
  cout<<ans<<endl;
  return 0;
}