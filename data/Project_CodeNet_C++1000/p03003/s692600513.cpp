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

const int N = 2e3 + 5;

ll n, m, dp[N][N];

int main(){
   IOS

   cin>>n>>m;

   vi s(n), t(m);

   for(int &x : s)cin>>x;
   for(int &x: t)cin>>x;

   memset(dp, 0, sizeof dp);

   for(int i = 0; i <= m; i++){
       dp[0][i] = 1;
   }
   for(int i = 0; i <= n; i++){
       dp[i][0] = 1;
   }

   for(int i = 1; i <= n; i++){
       for(int j = 1; j <= m; j++){
           if(s[i-1] == t[j-1]){
               dp[i][j] = (dp[i][j-1] + dp[i-1][j]) % mod;
           }else{
               dp[i][j] = (dp[i][j-1] + dp[i-1][j] - dp[i-1][j-1] + mod)%mod;
           }
       }
   }

 
   cout<<dp[n][m]<<"\n";










    







}

ll pwr(ll a, ll b){
   a %= mod;	//Remove mod if not required
   ll res = 1;
   while(b > 0){
    if(b&1)
        res = res * a % mod;
        a = a * a % mod;
    b >>= 1;
    }

    return res;
}

