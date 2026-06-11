#include<bits/stdc++.h>
//cervello|Phoenix
using namespace std;
#define ll long long int
#define eb emplace_back
#define mk make_pair
#define all(x) x.begin(),x.end()
#define mod 1000000007

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n; cin>>n;
  ll mx_x = INT_MIN, mx_y = INT_MIN, mn_x = INT_MAX , mn_y = INT_MAX;
  for(int i=0; i<n; i++){
    ll x, y; cin>>x>>y;
    mx_x = max(mx_x, (ll)x+y);
    mn_x = min(mn_x, (ll)x+y);
    mx_y = max(mx_y, (ll)x-y);
    mn_y = min(mn_y, (ll)x-y);
  }
  ll ans = max(mx_x-mn_x, mx_y-mn_y);
  cout<<ans<<"\n";
  return 0;
}