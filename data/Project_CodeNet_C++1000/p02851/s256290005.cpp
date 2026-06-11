// In god we trust
 
#include <bits/stdc++.h>
#include <chrono>
#include <algorithm>
#include <signal.h>
#include <thread>
 
#define pb push_back
#define fi first
#define se second
#define Vi vector<int>
#define Vb vector<bool>
#define Pi pair<int, int>
#define MP make_pair
#define MT make_tuple
#define INF 1000000000 
#define LINF 1000000000000000000
#define int long long
using namespace std;
using namespace std::chrono;
 

signed main(){
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  
  int n, k;
  cin >> n >> k;
  int a[n];
  
  for (int i = 0; i < n; i++){
    cin >> a[i];
    a[i]--;
    a[i] %= k;
  }

  int p_s[n];
  p_s[0] = a[0];
  int ans = 0;
  unordered_map<int, int> m;
  m[a[0]] = 1;
  for (int i = 1; i < n; i++){
    if (i >= k)
      m[p_s[i - k]]--;
    
    p_s[i] = (p_s[i - 1] + a[i]) % k;
    if (m.find(p_s[i]) != m.end())
      ans += m[p_s[i]];
    
    if (m.find(p_s[i]) != m.end())
      m[p_s[i]]++;
    else
      m[p_s[i]] = 1;
  }
  for (int i = 0; i < min(k - 1, n); i++){
    if (!p_s[i])
      ans++;
  }
  cout << ans << endl;

  
  
}
