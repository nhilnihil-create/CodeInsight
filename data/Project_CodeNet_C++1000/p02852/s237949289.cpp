#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define repit(it, li) for(auto it=li.begin(); it!=li.end(); it++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
   int n, m;
   cin>>n>>m;
   string s;
   cin>>s;

   reverse(s.begin(), s.end());
   int c=0;
   vector<int> stp;
   while(c<n){
      int d;
      for(d=min(m, n-c); d>0 && c+d<n+1 && s[c+d]=='1'; d--);
      if(d==0){
         cout<< (-1)<<endl;
         return 0;
      }
      stp.push_back(d);
      c+=d;
   }
   reverse(stp.begin(), stp.end());

   for(int e : stp) cout<<e<<" ";
   cout<<endl;
   return 0;
}
