#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i=0; i<n; ++i)
#define repit(it, li) for(auto it=li.begin(); it!=li.end(); it++)
#define ll long long int

int main(){
   int n;
   cin>>n;
   string s;
   cin>>s;

   char rgb[3]={'R', 'G', 'B'};

   ll cnt=0;
   int numi2[4000];
   rep(i0, 3) rep(i1, 3) rep(i2, 3) if(i0!=i1 && i1!=i2 && i0!=i2){
      int c0=rgb[i0], c1=rgb[i1], c2=rgb[i2];
      for(int i=n-1, sm=0; i>=0; i--){
         numi2[i]=sm;
         if(s[i]==c2) sm++;
      }

      rep(i, s.size()) if(s[i]==c0) for(int j=i+1; j<s.size(); j++) if(s[j]==c1){
         int discnt=0, dk=j+(j-i);
         if(dk<s.size() && s[dk]==c2) discnt=1;
         cnt+=numi2[j]-discnt;
      }
   }

   cout << cnt << endl;
   return 0;
}
