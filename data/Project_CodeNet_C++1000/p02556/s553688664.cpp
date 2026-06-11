#include <bits/stdc++.h>
using namespace std;

// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp> 
// using namespace __gnu_pbds; 

#define int long long
#define mod 1000000007
#define pb push_back
#define S second
#define F first
#define INF 1e18
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 

#define deb(x) cerr << "\n" \
                    << #x << "=" << x << "\n";
#define deb2(x, y) cerr << "\n" \
                        << #x << "=" << x << "\n" \
                        << #y << "=" << y << "\n";
#define w(x) \
  int x;     \
  cin >> x;  \
  while (x--)

int32_t main() {

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<pair<int,int>> v(n);
  for(auto &i: v)
    cin >> i.F >> i.S;
  
  int a = -INF,b = -INF; 
  sort(v.begin(),v.end());
  
  int ans = 0;
  
  for(auto i: v) {
   if(a != -INF) {
      ans = max(ans,i.F + i.S + a);
   }
    if(b != -INF) {
      ans = max(ans,i.F - i.S + b);
    }
    a = max(a,-i.F-i.S);
    b = max(b,-i.F+i.S);
  }

  cout << ans << '\n';
  return 0;
}
