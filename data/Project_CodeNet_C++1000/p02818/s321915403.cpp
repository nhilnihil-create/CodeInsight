#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define repit(it, li) for(auto it=li.begin(); it!=li.end(); it++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
   ll a, b, k;
   cin>>a>>b>>k;

   if(k<=a){
      a-=k;
   }
   else{
      k-=a;
      a=0;
      b=max((ll)0, b-k);
   }
   cout<<a<<" "<<b<<endl;

   return 0;
}
