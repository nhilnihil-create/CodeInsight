#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n) for(int i=0;i<(int)n;i++)
#define PI acos(-1)
#define fast_io ios_base::sync_with_stdio(false) ; cin.tie(0); cout.tie(0);
ll mod=1e9+7;

int main(){
    fast_io
   
   int n, x, t;
   cin >> n >> x >> t;
   int cnt = 0;
   int ans =0;
   while(cnt < n){
       cnt += x;
       ans += t;
   }
   cout << ans << endl;

   return 0;
}
