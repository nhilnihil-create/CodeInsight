#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i=0; i<n; ++i)
#define repit(it, li) for(auto it=li.begin(); it!=li.end(); it++)
#define ll long long int

int main(){
   int l;
   cin>>l;

   double a=(double)l/3;
   double ans=a*a*a;

   cout<< std::fixed << std::setprecision(15)<<ans<<endl;

   return 0;
}
