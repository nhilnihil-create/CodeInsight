#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int , int> pii;

const int N = 2e5+10 , mod = 1e9+7;

int32_t main(){
   ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
   int n , k;
   cin >> n >> k;
   map <int , int> mp;
   ll ans = 0;
   int cur = 0;
   mp[0] = 1;
   int sum[n];
   sum[0] = 0;
   for(int i = 1 ; i <= n ; i++){
      int x;
      cin >> x;
      x--;
      x %= k;
      cur = (cur + x) % k;
      sum[i] = cur;
      if(i >= k)
         mp[sum[i - k]]--;
      ans += mp[cur];
      mp[cur]++;
   }
   cout << ans;
   return 0;
}
