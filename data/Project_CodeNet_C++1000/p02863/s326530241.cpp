//Created by Kira

#include<bits/stdc++.h>
using namespace std;

#define IOS cin.sync_with_stdio(0);cin.tie(0); cout.tie(0);
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define pii pair<int,int> 
#define pb push_back
#define vi vector<int> 
using ll = long long;

const int mod = 1e9 + 7;

ll pwr(ll a, ll b);




int main(){
   IOS

   int n, T;
   cin>>n>>T;

   vector<pii> a(n);

   for(int i = 0; i < n; i++){
      cin>>a[i].first>>a[i].second;
   }
   sort(all(a));


   int dp[n + 1][T + 1];

   memset(dp, 0, sizeof dp);

   //dp[i][j] = ans for 1 to ith dish and time to finish is j mins

   for(int i = 0; i < n; i++){
      for(int t = 0; t < T; t++){
         if(i > 0)dp[i][t] = dp[i - 1][t];
         if(t >= a[i].first){
            dp[i][t] = max(dp[i][t], (i > 0 ? dp[i - 1][t - a[i].first] : 0) + a[i].second);
         }
      }
   }

   int mx = 0;
   for(int i = 1; i < n; i++){
      for(int t = 0; t < T; t++)
         mx = max(mx, dp[i - 1][t] + a[i].second);
   }

   cout<<mx<<"\n";


   // for(int i = 0; i < n; i++){
   //    for(int t = 0; t < T; t++){
   //       cout<<dp[i][t]<<" ";
   //    }cout<<endl;
   // }

   

}

ll pwr(ll a, ll b){
   a %= mod;	//Remove mod if not required
   ll res = 1;
   while(b > 0){
   if(b&1) res = res * a % mod;
        a = a * a % mod;
   b >>= 1;
    }

    return res;
}

