#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int , int> pii;
typedef long double ld;

const int N = 5e3+10 , mod = 1e9+7;

int c[N] , p[N] , cyc[N];
ll s[N] , sm[N][N] , mx[N][N];

void go(int v , int num , ll sum , int st){
   if(v == st && num != 0){
      cyc[st] = num;
      s[st] = sum;
      return;
   }
   sm[st][num + 1] = sum + c[v];
   if(num == 0)
      mx[st][num + 1] = sm[st][num + 1];
   else
      mx[st][num + 1] = max(mx[st][num] , sm[st][num + 1]);
   go(p[v] , num + 1 , sum + c[v] , st);
}

int32_t main(){
   ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
   int n , k;
   cin >> n >> k;
   for(int i = 0 ; i < n ; i++){
      cin >> p[i];
      p[i]--;
   }
   for(int i = 0 ; i < n ; i++)
      cin >> c[i];

   ll ans = -1ll * mod * mod;
   for(int i = 0 ; i < n ; i++){
      go(i , 0 , 0 , i);
      ll val = mx[i][min(k , cyc[i])];
      int rem = k % cyc[i];
      int m = k / cyc[i];
      if(rem == 0){
         m--;
         rem = cyc[i];
      }
      val = max(val , 1ll * m * s[i] + mx[i][rem]);
      ans = max(ans , val);
   }
   cout << ans;
   return 0;
}
