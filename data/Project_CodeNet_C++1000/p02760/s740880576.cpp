#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define repit(it, li) for(auto it=li.begin(); it!=li.end(); it++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
   int a[3][3];
   rep(i, 3) rep(j, 3) cin>>a[i][j];
   int n;
   cin>>n;  
   rep(_, n){
      int b;
      cin>>b;
      rep(i, 3) rep(j, 3) if(a[i][j]==b) a[i][j]= -1;
   }

   bool ok=false;
   rep(i, 3){
      bool f=true;
      rep(j, 3) if(a[i][j]!= -1) f=false;
      if(f) ok=true;
   }
   rep(j, 3){
      bool f=true;
      rep(i, 3) if(a[i][j]!= -1) f=false;
      if(f) ok=true;
   }
   {  
      bool f=true;
      rep(i, 3) if(a[i][i]!= -1) f=false;
      if(f) ok=true;
   }
   {  
      bool f=true;
      rep(i, 3) if(a[i][2-i]!= -1) f=false;
      if(f) ok=true;
   }
   
   if(ok) cout<<"Yes"<<endl;
   else cout<<"No"<<endl;
   return 0;
}
