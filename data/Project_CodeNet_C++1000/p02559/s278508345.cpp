#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder ;

int main()
{
  int n,q;
  cin>>n>>q ;
  fenwick_tree<long long> f(n);
  for(int i=0 ; i<n ; ++i)
  {
    int el;
    cin>>el;
    f.add(i,el);
  }


  for(int i=0 ; i<q ; ++i)
  {
    int t,u,x ;
    cin>>t>>u>>x ;
    if(t==0)
      f.add(u,x);
    else
      cout<<f.sum(u,x)<<"\n";
  }
  
  return 0;
}
