#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 3e5 + 5;
const int BITS = 61;
const int MOD = 1e9 + 7;


int suffix[N][BITS], a[N];

int32_t main() 
{
 
  ios::sync_with_stdio(0); 
  cin.tie(0); cout.tie(0);
 

  int n;
  cin >> n;
   
  for(int i = 1; i <= n; i++)
     cin >> a[i];

  for(int i = n; i > 0; i--){
     for(int j = 0; j < BITS; j++){
         suffix[i][j] += suffix[i + 1][j];
         suffix[i][j] += (a[i] >> j) & 1;
     }
  }
  
  int ans = 0;
  for(int i = 1; i <= n; i++){
     for(int j = 0; j < BITS; j++){
         if((a[i] >> j) & 1){
              int temp = (1LL << j) % MOD * (n - i - suffix[i + 1][j]) % MOD;
              temp %= MOD;
              ans += temp;
              ans %= MOD;
         } else{
              int temp = (1LL << j) % MOD * suffix[i + 1][j] % MOD;
              temp %= MOD;
              ans += temp;
              ans %= MOD;
         }
     }
  }

  cout << ans;

  return 0;
}