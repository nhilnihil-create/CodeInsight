#include<bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
#define pb push_back
#define mp make_pair
#define f(i,a,n) for(int i=a ; i<n ; i++)
#define rf(i,n,a) for(int i=n ; i>=a ; i--)
#define F first
#define S second
#define all(c) (c).begin(),(c).end()
#define sz(v) (int)(v).size()
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<pii,int> ppi;
typedef vector<pii> vpi;

const int inf = 1e9;
const int inf64 = 1e18;
const int MOD = 998244353;
int dp[3005][3005];

int32_t main(){
   fast;
   int n , s;
   cin >> n >> s;
   int a[n+1];
   f(i,1,n+1)  cin >> a[i];

   dp[0][0] = 1;
   for(int i=1 ; i<=n ; i++){
      for(int j=0 ; j<=s ; j++){
         dp[i][j] = (2 * dp[i-1][j]) % MOD;
         if(j - a[i] >= 0){
            dp[i][j] += dp[i-1][j-a[i]];
            dp[i][j] %= MOD;
         }
      }
   }

   cout << dp[n][s];
}