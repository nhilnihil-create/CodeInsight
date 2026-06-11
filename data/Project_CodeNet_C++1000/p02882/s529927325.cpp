#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define repit(it, li) for(auto it=li.begin(); it!=li.end(); it++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
   int a, b, x;
   cin>>a>>b>>x;

   double ans;
   double c=(double)2*x/(a*b);
   if(c<=a){
      double t=atan(c/b);
      ans=90-t/(2*M_PI)*360;
   }
   else{
      double y=a*a*b-x;
      c=2*y/(a*a);
      double t=atan(c/a);
      ans=t/(2*M_PI)*360;
   }

   cout<<std::setprecision(15)<<ans<<endl;
   return 0;
}
