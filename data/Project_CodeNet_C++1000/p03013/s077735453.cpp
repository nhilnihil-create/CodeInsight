#include <bits/stdc++.h>


using namespace std;

#define ll long long
#define mk make_pair
#define pb push_back
#define ff first
#define sc second
#define all(x) x.begin(), x.end()
#define sz(x) (x).size()

ll gcd(ll a, ll b);

ll sum(int n);

uint64_t MOD = 1e9 + 7;
void go(){
   int n,m;cin>>n>>m;
   map<int, bool> broken;
   for(int i=0;i<m;i++){
      int b;cin>>b;
      broken[b]=true;
   }
   vector<uint64_t> dp(n+2, 0);
   dp[0]=0;
   dp[1]=1;
   for(int i=2;i<n+2;i++){
      if(broken[(i-2)+1]==true){
         dp[i]=0;
         continue;
      }
      dp[i]=(dp[i-1]+dp[i-2])%MOD;
   }
   
   uint64_t ans=dp[n+1];
   cout << ans;
}
int main(){
   
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);

   go();

   return 0;
}

ll gcd(ll a, ll b){     
   if(b == 0) return a;
   
   return gcd(b, a % b);
}

ll sum(int n){                
   if(n == 0){
      return n;
   }else{
      return sum(n/10) + n%10;
   }
}
