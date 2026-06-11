#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define repit(it, li) for(auto it=li.begin(); it!=li.end(); it++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
   int n, m;
   cin>>n>>m;
   vector<int> d(n, -1);
   bool ok=true;
   rep(_, m){
      int s, c;
      cin>>s>>c; s--;

      if(d[s]== -1 || d[s]==c) d[s]=c;
      else ok=false;
   }

   if(n>=2 && d[0]==0) ok=false;
   if(n>=2 && d[0]== -1) d[0]=1;

   int ans=0;
   if(ok){
      rep(i, n){
         ans*=10;
         if(d[i]!= -1) ans+=d[i];
      }
   }
   else ans= -1;

   cout<<ans<<endl;
   return 0;
}
