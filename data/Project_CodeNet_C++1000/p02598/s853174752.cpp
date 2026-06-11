#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/* clang-format off */
#define MOD 1000000007
#define INF 1000000000
#define REP(i, n) for (ll i = 0, i##_len = (n); i < i##_len; ++i)
#define ALL(a) (a).begin(), (a).end()
#define __DEBUG__
#ifdef __DEBUG__
#define CH_P(a) cout <<"check_point("<<#a<<")" << "\n";
#define DEBUG(x) cout<<#x<<":"<<x<<"\n"
#define DEBUGS(v) cout << #v << ":";for(auto x:v){cout<<x<<" ";}cout<<"\n"
#endif
#ifndef __DEBUG__
#define CH_P(a) 
#define DEBUG(x) 
#define DEBUGS(v) 
#endif
#define TIMER_S(start) chrono::system_clock::time_point start = chrono::system_clock::now();
#define TIMER_E(end) chrono::system_clock::time_point end = chrono::system_clock::now();
#define TIME(start, end) cout << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count()) << "ms" << "\n";
/* clang-format on */
ll n;
vector<ll> a;
bool is_OK(ll lim, ll k) {
  ll ttl = 0;
  REP(i, n) {
    ttl+=(ll)ceil((double)a[i]/lim)-1;
  }
  return k >= ttl;
}

ll binary_search(ll k) {
  ll ng = 0;
  ll ok = a.back() + 1;

  while (abs(ng - ok) > 1) {
    ll mid = (ok + ng) / 2;
    if (is_OK(mid, k))
      ok = mid;
    else
      ng = mid;
  }
  return ok;
}

int main() {
  ll  k;
  cin >> n >> k;

  REP(i, n) {
    ll tmp;
    cin >> tmp;
    a.push_back(tmp);
  }
  sort(ALL(a));
  cout << binary_search(k) << endl;

  return 0;
}
