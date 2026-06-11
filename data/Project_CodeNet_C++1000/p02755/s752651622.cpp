#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define repit(it, li) for(auto it=li.begin(); it!=li.end(); it++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
   int a, b;
   cin>>a>>b;

   rep(c, 10000) if(c*8/100==a && c*10/100==b){
      cout<<c<<endl;
      return 0;
   }
   cout<< (-1) <<endl;
   return 0;
}
