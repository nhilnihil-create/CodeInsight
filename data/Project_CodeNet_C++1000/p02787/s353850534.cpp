#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define repit(it, li) for(auto it=li.begin(); it!=li.end(); it++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
   int h, n;
   cin>>h>>n;
   vector<int> a(n), b(n);
   rep(i, n) cin>>a[i]>>b[i];

   vector<int> dp(10001, INT_MAX);//nokori j hp de tukatta mp
   dp[h]=0;
   rep(i, n){
      for(int j=10000; j>=0; j--) if(dp[j]!=INT_MAX){
         int dj=max(0, j-a[i]);
         dp[dj]=min(dp[dj], dp[j]+b[i]);
      }
   }

   cout<<dp[0]<<endl;
   return 0;
}
