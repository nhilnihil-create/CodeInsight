#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long
#define pb push_back
#define sz(i) (int)(i.size())
#define F first
#define S second
#define L long double
#define P pair<int, int>
const int inf = 0x3f3f3f3f3f3f3f3LL;
const int mod = (int)1e9 + 7;
using namespace std;
#if LOCAL
#include "../../tr.h"
#else
#define tr(...)
#define endl '\n'
#endif
template<class T> void smin(T& a, T val) {if (a > val) a = val;}template<class T> void smax(T& a, T val) {if (a < val) a = val;}
const int N = 305;

int n, a[N], k;
int dp[N][N][N];

int solve(int idx, int rem, int prev){
   if(rem < 0)
      return inf;
   if(idx > n)
      return 0;
   int &ans = dp[idx][rem][prev];
   if(~ans)
      return ans;
   ans = inf;
   smin(ans, solve(idx+1, rem-1, prev));
   smin(ans, max(0LL, a[idx] - a[prev]) + solve(idx+1, rem, idx));
   return ans;
}

int32_t main(){_

   cin>>n>>k;

   for (int i = 1; i <= n; ++i)
   {
      cin>>a[i];
   }   
      
   memset(dp, -1, sizeof dp);
   cout<<solve(1, k, 0);

   return 0;
}