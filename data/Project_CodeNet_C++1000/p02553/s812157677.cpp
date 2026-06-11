#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<math.h>
#include<set>
#include<map>
#include<time.h>
#include<cstring>
#include<iomanip>
#include<numeric>
#include<list>
#include<stack>
#define lli long long int
#define h 10000
#define pf push_front
#define pb push_back
#define ub upper_bound
#define lb lower_bound
using namespace std;
int main() 
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL) ;
  lli a, b, c, d;
  cin>>a>>b>>c>>d;
  if(b<=0 && d<=0)cout<<a*c<<endl;
  else if(b<=0)
  {
  	if(c<=0)cout<<a*c<<endl;
  	else cout<<c*b<<endl;
  } 
  else if(d<=0)
  {
  	if(a<=0)cout<<a*c<<endl;
  	else cout<<a*d<<endl;
  } 
  else
  cout<<max(a*c,b*d)<<endl;
  return 0;
} 
