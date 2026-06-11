#define rep(i, a, b) for(int i = a; i < (int)(b); i++)
#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
template<class T> inline void chmax(T &a, const T &b) {if(a < b) a = b;}
template<class T> inline void chmin(T &a, const T &b) {if(a > b) a = b;}
const long long INF = 1LL<<60;
const long long MOD = (ll)1e9+7;
const long long MAX = (ll)1e5+100;


int main(void) {
   ll N;
   cin>>N;
   // vector<ll> P(N);
   // rep(i,0,N)cin>>P[i];
   //num, idx
   map<ll,ll> P;
   rep(i,0,N) {
      ll p;
      cin>>p;
      P[p-1] = i;
   }
   set<ll> vP;
   ll range[4] = {0,0,0,0};
   ll ans = 0;
   for(int i = N-1; i>=0;i--) {
      auto itr = vP.upper_bound(P[i]);
      if (itr != vP.end()) {
         range[2] = *itr - P[i];
         auto itr2 = itr;
         itr2++;
         if (itr2!= vP.end()) {
            range[3] = *itr2 - *itr;
         } else {
            range[3] = N -1 - *itr + 1;
         }
      } else {
         range[2] = N-1 - P[i] + 1;
         range[3] = 0;
      }
      itr = vP.upper_bound(P[i]);
      if (itr != vP.begin()) {
         itr--;
         range[0] = P[i] - *itr;
         auto itr2 = itr;
         if (itr2 != vP.begin()) {
            itr2--;
            range[1] = *itr - *itr2;
         } else {
            range[1] = *itr - 0 + 1;
         }
      } else {
         range[0] = P[i] - 0 + 1;
         range[1] = 0;
      }
      vP.insert(P[i]);
      // cout<<i<<" "<<range[0]<<" "<<range[1]<<endl;
      // cout<<i<<" "<<range[2]<<" "<<range[3]<<endl;
      ans += (i+1) * (range[3] * range[0]);
      ans += (i+1) * (range[2] * range[1]);
   }
   cout<<ans<<endl;








   return 0;
}