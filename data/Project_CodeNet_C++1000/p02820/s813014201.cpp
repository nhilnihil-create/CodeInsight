#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define repit(it, li) for(auto it=li.begin(); it!=li.end(); it++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
   int n, k;
   cin>>n>>k;
   int r, s, p;
   cin>>r>>s>>p;
   string t;
   cin>>t;

   int sc=0;
   rep(i, k){
      char pre=0;
      for(int j=i; j<n; j+=k){
         if(t[j]!=pre){
            if(t[j]=='r') sc+=p;
            if(t[j]=='s') sc+=r;
            if(t[j]=='p') sc+=s;
            pre=t[j];
         }
         else pre=0;
      }
   }

   cout<<sc<<endl;
   return 0;
}
