#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#define ll long long
using namespace std;
int main()
{
  ll a,zheng,xiao,ans,dd;int b,c,d;
  cin >> a;
  getchar();
  scanf("%d.%d",&b,&c);
  d=b*100+c;
  dd=(ll)d;
  ans=(a*d)/100;

  
  cout << ans;
 
}