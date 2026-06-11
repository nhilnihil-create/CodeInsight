#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
  int x;
  cin>>x;
  
  int r = x*360/__gcd(x,360);
  int ans = r/x;
  
  cout<<ans<<endl;
}