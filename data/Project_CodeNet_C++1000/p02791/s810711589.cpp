#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define repit(it, li) for(auto it=li.begin(); it!=li.end(); it++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
   int n;
   cin>>n;
   int mn=INT_MAX;
   int cnt=0;
   rep(i, n){
      int p;
      cin>>p;
      if(p<=mn) cnt++;
      mn=min(mn, p);
   }

   cout<<cnt<<endl;
   return 0;
}
