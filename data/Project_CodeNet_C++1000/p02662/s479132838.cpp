//verma_ankit484

#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>

#define int long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define pb push_back
const int mod = (int) 998244353;

using namespace std;
//using namespace __gnu_pbds;

//#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

int powrr[3001];

int power(int base, int exp) {
    int res=1;
    while (exp > 0) {
       if (exp % 2 == 1) res = (res * base) % mod;
       base = (base * base) % mod;
       exp /= 2;
    }
    return res % mod;
}

void calc() {
  int s = 0;
  powrr[0] = 1;
  s = 0;
  for (int i = 1; i <= 3000; i++) {
    s = power(2, i);
    s %= mod;
    powrr[i] = s;
  }
}

int dp[3002][3002];
vector<int> vc;
int n, s;

int rec(int idx, int sum) {
  if (sum > s) return 0;
  if (sum == s) {
    return powrr[n - idx];
  }  
  if (idx == n) return 0;
  int &ans = dp[idx][sum];
  if (ans != -1) return ans;
  ans = rec(idx + 1, sum + vc[idx]);
  ans += (2 * rec(idx + 1, sum));
  ans %= mod;
  return ans;
}

int32_t main() {
  IOS
  #ifdef AV
  freopen("input.txt", "r", stdin);
  #endif
  calc();
  memset(dp, -1, sizeof dp);
  cin >> n >> s;
  vc.resize(n);
  for (auto &i: vc) cin >> i;
  cout << rec(0, 0) << endl;
  return 0;
}
