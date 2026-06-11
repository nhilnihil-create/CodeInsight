#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define repit(it, li) for(auto it=li.begin(); it!=li.end(); it++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int num[10][10];

int main(){
   int n;
   cin>>n;

   for(int i=1; i<=n; i++){
      int b=i%10, t;
      for(t=i; t/10!=0; t/=10);
      num[t][b]++;
   }

   // for(int a=1; a<=9; a++) for(int b=1; b<=9; b++){
   //    cout<<a<<","<<b<<"  "<<num[a][b]<<endl;
   // }

   ll ans=0;
   for(int a=1; a<=9; a++) for(int b=a; b<=9; b++){
      if(a==b) ans+= num[a][a]*num[a][a];
      else ans+=(ll)2*num[a][b]*num[b][a];
   }

   cout<<ans<<endl;
   return 0;
}
