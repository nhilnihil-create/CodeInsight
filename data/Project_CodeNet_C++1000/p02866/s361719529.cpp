#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
using ll = long long;
const int INF = 2147483647;
const ll MOD = 998244353;
// const ll INF = 1000000000000000000LL;

int main(){
   int n;
   cin >> n;
   vector<ll> d(n);
   rep(i,n) cin >> d[i];
   bool zf = false;
   if(d[0]!=0) zf = true;
   for(int i=1;i<n;i++){
      if(d[i]<1) zf = true;
   }
   if(zf){
      cout << 0 << endl;
      return 0;
   }
   map<ll,ll> mp;
   rep(i,n){
      mp[d[i]]++;
   }
   ll ans=1;
   ll before;
   bool flag=false;
   if(*max_element(d.begin(),d.end())+1!=mp.size()){
      cout << 0 << endl;
      return 0;
   }
   for(auto a:mp){
      if(flag){
         rep(i,a.second) ans = ans*before%MOD;
         flag = false;
      }
      if(a.second>1){
         flag = true;
         before = a.second;
      }
   }
   cout << ans%MOD << endl;
   return 0;
}