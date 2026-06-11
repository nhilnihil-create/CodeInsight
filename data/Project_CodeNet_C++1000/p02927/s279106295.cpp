#define rep(i, a, b) for(int i = a; i < (int)(b); i++)
#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
template<class T> inline void chmax(T &a, const T &b) {if(a < b) a = b;}
template<class T> inline void chmin(T &a, const T &b) {if(a > b) a = b;}
const long long INF = 1LL<<60;

const ll MAXN = (ll)2e3+10;
const ll DIV = (ll)1e9+7;


int main(void) {
   ll M,D;
   cin>>M>>D;
   ll ans = 0;
   rep(j,1,M+1) rep(i,1,D+1) {
      if (j == (i/10)*(i%10)) {
         if (i/10==1) continue;
         if (i%10==1) continue;
         ans ++;
         // cout<<j<<" "<<i<<endl;
      }
   }
   cout<<ans<<endl;
   return 0;
}