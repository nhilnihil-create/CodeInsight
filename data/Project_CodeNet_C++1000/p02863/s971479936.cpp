#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define repit(it, li) for(auto it=li.begin(); it!=li.end(); it++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

static int dp[3000][3000][2];

int main(){
   int n, t;
   cin>>n>>t;
   vector<int> a(n), b(n);
   rep(i, n) cin>>a[i]>>b[i];

   // int dp[3000][2];
   rep(i, n) rep(j, t) rep(k, 2) dp[i][j][k]=0;

   auto upd=[](int& a, int b){a=max(a, b);};

   // dp[t-1][0]=0 start
   rep(i, n){
      rep(j, t){
         rep(k, 2) upd(dp[i][j][k], (i==0)?0:dp[i-1][j][k]);
         rep(k, 2) if(j-a[i]>=0) upd(dp[i][j-a[i]][k], ((i==0)?0:dp[i-1][j][k])+b[i]);
         upd(dp[i][j][1], ((i==0)?0:dp[i-1][j][0])+b[i]);
      }
   }

   int mx=0;
   rep(i, n) rep(j, t) rep(k, 2) mx=max(mx, dp[i][j][k]);

   cout<<mx<<endl;
   return 0;
}
