#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int , int> pii;

const int N = 2e5+10 , mod = 1e9+7;

int32_t main(){
   ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
   int n;
   cin >> n;
   int x[n] , l[n];
   vector <pii> v;
   for(int i = 0 ; i < n ; i++){
      cin >> x[i] >> l[i];
      v.push_back({x[i] - l[i] , i});
   }
   sort(v.begin() , v.end());
   int mx = -mod;
   int ans = 0;
   for(pii xx : v){
      if(mx > xx.first){
         ans++;
         mx = min(mx , x[xx.second] + l[xx.second]);
      }
      else{
         mx = x[xx.second] + l[xx.second];
      }
   }
   cout << n - ans;
   return 0;
}
