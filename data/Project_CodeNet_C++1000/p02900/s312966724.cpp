
#include<bits/stdc++.h>
using namespace std;

using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
 
template<class Z> map<Z, int> factorize(Z n) {
  map<Z, int> res;
  for (Z i = 2; i * i <= n; ++i) while (n % i == 0) ++res[i], n /= i;
  if (n != 1) ++res[n];
  return res;
}


int main()
{


     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
   /* #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
   */

   long long int a,b;
   cin>>a>>b;
   long long int num=__gcd(a,b);
   auto mp=factorize(num);
   cout<<mp.size()+1<<endl;

       return 0;
    
}