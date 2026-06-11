#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < (n);i++)
using ll = long long;
const ll MOD=1000000007;


ll gcd(ll a,ll b)
{
   if(a%b==0)
   {
       return(b);
   }
   else
   {
       return(gcd(b,a%b));
   }
}

ll lcm(ll a,ll b)
{
   return a/gcd(a,b)*b;
}


int main() 
{
  ll A,B,C,D; cin>>C>>D>>A>>B;
  ll kosuA_C=(C-1)/A;
  //cout<<kosuA_C<<endl;
  ll kosuA_D=D/A;
  //cout<<kosuA_D<<endl;
  ll kosuB_C=(C-1)/B;
  //cout<<kosuB_C<<endl;
  ll kosuB_D=D/B;
  //cout<<kosuB_D<<endl;
  ll kosuAB_C=(C-1)/(lcm(A,B));
  //cout<<kosuAB_C<<endl;
  ll kosuAB_D=D/(lcm(A,B));
  //cout<<kosuAB_D<<endl;
  cout<<(D-C+1)-((kosuA_D-kosuA_C)+(kosuB_D-kosuB_C)-(kosuAB_D-kosuAB_C))<<endl;
  return 0;
}
