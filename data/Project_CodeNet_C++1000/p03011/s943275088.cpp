#include<iostream>
#include<algorithm>
using namespace std;
int main (void)
{
 int p,q,r;
  cin>>p>>q>>r;
  cout<<min(min(p+q,p+r),q+r)<<endl;
}
 