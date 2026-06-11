#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int , int> pii;

const int N = 2e5+10 , mod = 1e9+7;

int32_t main(){
   ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
   int n;
   cin >> n;
   int ans = 0;
   for(int i = 1 ; i <= n ; i++){
      int x;
      cin >> x;
      if(i % 2 == 1 && x % 2 == 1)
         ans++;
   }
   cout << ans;
   return 0;
}
