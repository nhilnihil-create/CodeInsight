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

signed main(){
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);

  int x, y, a, b, c;
  cin >> x >> y >> a >> b >> c;
  int p[a], q[b], r[c];
  
  for (int i = 0; i < a; i++)
    cin >> p[i];
  for (int i = 0; i < b; i++)
    cin >> q[i];
  for (int i = 0; i < c; i++)
    cin >> r[i];

  sort(p, p + a, greater<>());
  sort(q, q + b, greater<>());
  sort(r, r + c, greater<>());
  int pp = x - 1;
  int qq = y - 1;
  int rr = 0;
  int min_ = min(p[pp], q[qq]);
  int best = r[rr];

  int ans = 0;
  for (int i = 0 ; i < x; i++)
    ans += p[i];
  for (int j = 0; j < y; j++)
    ans += q[j];
  
  while(best > min_){
    ans += best - min_;
    if (p[pp] == min_)
      pp--;
    else
      qq--;
    rr++;
    min_ = min(pp >=0 ? p[pp] : LINF, qq >= 0 ? q[qq] : LINF);
    best = rr < c ? r[rr] : 0;
  }
  cout << ans << endl;
  
}
