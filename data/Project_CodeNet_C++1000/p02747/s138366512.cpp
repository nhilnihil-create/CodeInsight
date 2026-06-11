#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i=0; i<n; ++i)
#define repit(it, li) for(auto it=li.begin(); it!=li.end(); it++)
#define ll long long int

int main(){
   string s;
   cin>>s;
   string hi="hi";
   bool ok=true;
   if(s.size()%2==0){
      rep(i, s.size()){
         if(s[i]!=hi[i%2]) ok=false;
      }
   }
   else ok=false;
   cout << (ok?"Yes":"No") << endl;
   return 0;
}
