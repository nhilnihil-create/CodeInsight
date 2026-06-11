// In god we trust
 
#include <bits/stdc++.h>
#include <chrono>
#include <algorithm>
#include <signal.h>
#include <thread>
#include <pthread.h>
#include <omp.h>
 
#define pb push_back
#define fi first
#define se second
#define Vi vector<int>
#define Vb vector<bool>
#define Pi pair<int, int>
#define MP make_pair
#define MT make_tuple
#define Q queue
#define Qi Q<int>
#define INF 1000000000 
#define LINF 1000000000000000000
#define int long long
#define _USE_MATH_DEFINES
using namespace std;
using namespace std::chrono;

unordered_map<int, int> factor(int n){
  int cnt = 0;
  unordered_map<int, int> m;
  int nn = n;
  while (!(nn & 1))
    cnt++, nn /= 2;
  if(cnt)
    m[2] = cnt;
  for (int i = 3; i <= sqrt(n); i++){
    cnt = 0;
    while(nn % i == 0)
      nn /= i, cnt++;
    if (cnt)
      m[i] = cnt;
  }
  if (nn > 2)
    m[nn] = 1;
  
  return m;
}

bool m[1100][1100];
Vi g[1001000];

signed main(){
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);

  int mod = 1e9 + 7;

  int n, k;
  cin >> n >> k;
  int ans = 0;
  for (int i = k; i < n + 2; i++){
    ans += (i * (2 * n - (i - 1)) / 2 - ((i - 1) * i / 2) + 1) % mod;
    ans %= mod;
  }
  cout << ans << endl;
  
}
