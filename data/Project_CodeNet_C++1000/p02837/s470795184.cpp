#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define repit(it, li) for(auto it=li.begin(); it!=li.end(); it++)
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main(){
   int n;
   cin>>n;
   vector<int> x[15], y[15];
   rep(i, n){
      int a;
      cin>>a;
      rep(j, a){
         int ix, iy;
         cin>>ix>>iy; ix--;
         x[i].push_back(ix);
         y[i].push_back(iy);
      }
   }

#define isPure(k) ((co>>(k))&1)
   int mx=0;
   for(int co=0; co<(1<<n); co++){
      bool ok=true;
      int cnt=0;
      rep(i, n) if(isPure(i)){
         rep(j, x[i].size()) if(y[i][j] != isPure(x[i][j])){
            ok=false;
         }
         cnt++;
      }
      if(ok) mx=max(mx, cnt);
   }

   cout<<mx<<endl;
   return 0;
}
