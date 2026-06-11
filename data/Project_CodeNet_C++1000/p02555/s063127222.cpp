#include <bits/stdc++.h>
using namespace std;

// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp> 
// using namespace __gnu_pbds; 

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
const int N = 2001;
int dp[N];

int go(int num) {
  if(num == 0)
    return 1;
  if(num < 0)
    return 0;
  
  if(dp[num] != -1)
    return dp[num];
 
  int ans = 0;
  for(int i = 3; i <= num; ++i)
    ans = (ans % mod + go(num - i) % mod) % mod;
  
  return dp[num] = ans;
}

int32_t main() {

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  memset(dp,-1,sizeof dp);
  cin >> n;
  cout << go(n);
  return 0;
}
