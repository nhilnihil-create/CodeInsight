#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define repit(it, li) for(auto it=li.begin(); it!=li.end(); it++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
   int n;
   cin>>n;
   bool ok=true;
   rep(i, n){
      int a;
      cin>>a;

      if(a%2==0 && a%3!=0 && a%5!=0) ok=false;
   }

   if(ok) cout<<"APPROVED"<<endl;
   else cout<<"DENIED"<<endl;
   return 0;
}
