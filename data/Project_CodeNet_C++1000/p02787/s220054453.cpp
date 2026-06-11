//g++ -std=gnu++14 a.cpp
//#include <bits/stdc++.h>

#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <iostream>
#include <istream>
#include <iterator>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <tuple>
#include <iomanip>
#include <random>
#include <math.h>

using namespace std;

#define ll long long
#define rep(i, n) for(ll i = 0; i < (n); i++)
ll MOD = 1e9 + 7;
int INF = 1 << 30;
ll INFL = 1LL << 60;

ll atack(ll x){
  if(x == 1){
    return 1;
  }else{
    ll t = atack(x/2);
    return t*2 + 1;
  }
}

int main(){
   int H,N;
   cin >> H >> N;
   vector<ll> A(N),B(N);
   rep(i,N)cin >> A[i] >> B[i];
   vector<vector<ll>> dp(N+1,vector<ll> (H+1));
   rep(i,N+1)dp[i][0] = 0;
   rep(i,H+1)dp[0][i] = INFL;
   dp[0][0] = 0;

   for(int i = 1;i <= N;i++){
     for(int j = 1;j <= H;j++){
       dp[i][j] = (j-1+A[i-1])/A[i-1];
       dp[i][j] *= B[i-1];
     }
   }
/*
   rep(i,N+1){
     rep(j,H+1){
       cout << dp[i][j] << " ";
     }
     cout << endl;
   }
*/
   for(int i = 1;i <= N;i++){
     for(int j = 1;j <= H;j++){
        if(dp[i][j] > dp[i-1][j])dp[i][j] = dp[i-1][j];
/*
        for(int k = 0;k <= j/A[i-1];k++){
          if(dp[i][j] > dp[i-1][j-k*A[i-1]]  + B[i-1]*k)dp[i][j] = dp[i-1][j-k*A[i-1]]  + B[i-1]*k;
        }
*/
        ll jj = j-A[i-1];
        if(dp[i][j] > dp[i-1][jj] + B[i-1]){
          dp[i][j] = dp[i-1][jj] + B[i-1];
        }
        if(dp[i][j] > dp[i][jj] + B[i-1])dp[i][j] = dp[i][jj] + B[i-1];
/*

        ll jj = j-A[i-1];
        while(jj >= 0){
          if(jj >= 0){
            if(dp[i][j] > dp[i-1][jj] + B[i-1]){
              dp[i][j] = dp[i-1][jj] + B[i-1];

          }
          jj -= A[i-1];
        }


      }
      */
     }
   }
/*
   for(int i = 1;i <= N;i++){
     for(int j = 1;j <= H;j++){
       cout << dp[i][j] << " ";
     }
     cout << endl;
   }
*/

   cout << dp[N][H] << endl;
}
