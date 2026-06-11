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
#include<sstream>
#define lli long long int
#define h 1000000007
#define s 10000
#define pf push_front
#define pb push_back
#define ub upper_bound
#define lb lowepr_bound
#define mp make_pair
#define pi 3.14159
using namespace std;
int main() 
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL) ;
  lli n, fact=1,i, fact2=1,ans,fact3=1;
  cin>>n;
  for(i=1;i<=n;i++) 
  fact=((fact%h)*10)%h;
  for(i=1;i<=n;i++) 
  fact2=((fact2%h)*8)%h;
  for(i=1;i<=n;i++) 
  fact3=((fact3%h)*9)%h;
  ans=(fact-(fact3+fact3-fact2))%h;
  if(ans<0){ans+=h;} 
  cout<<ans<<endl;
  return 0;
} 
