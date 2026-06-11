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
   ll N;
   cin>>N;
   ll ans = ceil(log2(N));
   // cout<<ans<<endl;
   ll A[N][N];
   rep(i,0,N) rep(j,0,N) A[i][j] = 0;
   rep(i,0,N) rep(j,0,N) {
      rep(k,1,ans+1) {
         if (i%(int)pow(2,k) != j%(int)pow(2,k)) {
            A[i][j] = k;
            break;
         }
      }
   }
   rep(i,0,N) {
      rep(j,0,N) {
         if (i>=j) continue;
         cout<<A[i][j]<<" ";
      }
      cout<<endl;
   }



   return 0;
}