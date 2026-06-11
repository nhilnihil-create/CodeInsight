#include <bits/stdc++.h>
#define Int int64_t
#define pb push_back
using namespace std;

int main()
{
   Int N;cin>>N;
   string S,T;
   
   cin>>S>>T;
   string ans="";
   for(int i=0;i<S.length();++i){
       ans.pb(S[i]);
       ans.pb(T[i]);
   }
   cout<<ans<<"\n";
   
   
}