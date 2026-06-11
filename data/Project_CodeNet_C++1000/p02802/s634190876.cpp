#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define repit(it, li) for(auto it=li.begin(); it!=li.end(); it++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
   int n, m;
   cin>>n>>m;

   vector<int> wa(n);
   vector<bool> ac(n);
   int swa=0, sac=0;
   rep(i, m){
      int p;
      string s;
      cin>>p>>s;

      if(ac[p]) continue;
      if(s=="WA") wa[p]++;
      else{
         ac[p]=true;
         sac++;
         swa+=wa[p];
      }
   }

   cout<<sac<<" "<<swa<<endl;
   return 0;
}
