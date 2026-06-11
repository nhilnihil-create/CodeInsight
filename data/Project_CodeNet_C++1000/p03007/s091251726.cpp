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
   vector<ll> A(N);
   rep(i,0,N) cin>>A[i];
   ll id[2] = {min_element(A.begin(),A.end()) - A.begin(),max_element(A.begin(),A.end()) - A.begin()};
   // cout<<id[0]<<" "<<id[1]<<endl;
   if (id[1]==id[0]) {
      id[0] = 0;
      id[1] = N-1;
   }
   vector<pair<ll,ll>> va;
   rep(i,0,N) {
      if (i==id[0]) continue;
      if (i==id[1]) continue;
      if (A[i]<=0) {
         // cout<<A[id[1]]<<" "<<A[i]<<endl;
         va.push_back(make_pair(A[id[1]],A[i]));
         A[id[1]] -= A[i];
      } else {
         // cout<<A[id[0]]<<" "<<A[i]<<endl;
         va.push_back(make_pair(A[id[0]],A[i]));
         A[id[0]] -= A[i];
      }
   }
   // cout<<A[id[1]]<<" "<<A[id[0]]<<endl;
   va.push_back(make_pair(A[id[1]],A[id[0]]));
   cout<<A[id[1]] - A[id[0]]<<endl;
   for (auto el: va) {
      cout<<el.first<<" "<<el.second<<endl;
   }




   return 0;
}