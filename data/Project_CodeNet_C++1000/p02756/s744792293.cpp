#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define repit(it, li) for(auto it=li.begin(); it!=li.end(); it++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
   string s, r;
   cin>>s;
   int q;
   cin>>q;
   bool fl=false;
   rep(_, q){
      int t;
      cin>>t;
      if(t==1){
         fl= !fl;
      }
      else{
         int f;
         char c;
         cin>>f>>c;
         if((f==1) ^ (fl)) r+=string(1, c);
         else s+=string(1, c);
      }
   }

   if(!fl){
      reverse(r.begin(), r.end());
      cout<<r<<s<<endl;
   }
   else{
      reverse(s.begin(), s.end());
      cout<<s<<r<<endl;
   }
   return 0;
}
