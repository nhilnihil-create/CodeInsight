#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i=0; i<n; ++i)
#define repit(it, li) for(auto it=li.begin(); it!=li.end(); it++)
#define ll long long int

int main(){
   ll a;
   string b;
   cin>>a>>b;

   int ran=b.size()+2;
   rep(i, b.size()) if(b[i]=='.') ran=i+2+1;
   ll b100=0;
   for(int i=0; i<ran; i++){
      if(b[i]!='.'){
         b100*=10;
         if(i<b.size()) b100+=(b[i]-'0');
      }
   }

   cout << a*b100/100 << endl;
   return 0;
}
