#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int,int> P;


P pmake(int x)
{
   int a = x%10;
  
   int b=0;
   while(x>0)
   {
       b= x;
      x /=10;
   }

  return P(a,b);

}



int main()
{
  int n;
  cin>>n;
  ll ans =0;
  
  map<P,int>ma;
  for(int i=1;i<=n;i++)
  {
      P p = pmake(i);
  
      ma[p]++;
  
  }
  
  for(int i=1;i<=n;i++)
  {
     P p = pmake(i);
     
     P q(p.second,p.first);
  
     ans += ma[q];

  }
  
  
  cout<<ans<<endl;
  
  
    return 0;

}
