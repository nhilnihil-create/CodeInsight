#include <bits/stdc++.h>
#define rep0(i,b) for(int i=0 ; i< b ;i++)
#define rep1(i,b) for(int i=1 ; i<=b ;i++)
#define reps(i,a,b) for(int i=a ; i< b.length() ;i++)
typedef long long ll;
#define MOD 1000000007
# define M_PI     3.14159265358979323846

using namespace std;


int main()
{
  ll a,b,c,k,res=0;
  cin>>a>>b>>c>>k;


  if(a>=k)
      res = k;
  else if(a+b>=k)
    res = a;
  else if (a+b<k)
    res = a - (k-a-b);

cout<<res;


  return 0 ;
}
