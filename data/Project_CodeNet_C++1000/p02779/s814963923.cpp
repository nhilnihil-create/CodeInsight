#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define repit(it, li) for(auto it=li.begin(); it!=li.end(); it++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
   int n;
   cin>>n;
   bool ye=true;
   map<int, bool> deta;
   rep(i, n){
      int a;
      cin>>a;
      if(deta[a]) ye=false;
      deta[a]=true;
   }

   if(ye) cout<<"YES"<<endl;
   else cout<<"NO"<<endl;
   return 0;
}
