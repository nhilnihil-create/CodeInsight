#include <bits/stdc++.h>

#define rep(i, n) for (ll i = 0; i < (n); i++)
#define rep2(i, a, b) for (ll i = (a); i < (b); i++)
typedef uint64_t ull;
typedef int64_t ll;
typedef std::pair<ll, ll> PLL;

using namespace std;

ll N;
vector<ll> a;
vector<ll> psum;

ll _sum(ll t) {
  ll ng = -1, ok = N;
  while(ng+1 < ok) {
    ll m = (ok+ng)/2;
    if (a[m] >= t){
      ok = m;
    } else {
      ng = m;
    }
  }
  ll pos = ok;
  if (pos == 0) {
    return t*N;
  }
  // printf("%d + %dx%d\n",psum[pos-1],t,(N-pos));
  return psum[pos-1] + t*(N-pos);
}

ll solve(ll k) {
  ll ok = 0, ng = 300010;
  while(ok+1 < ng) {
    ll m = (ok+ng)/2;
    if (_sum(m) >= m*k) {
      ok = m;
      // printf("ok=%d\n", m);
    } else {
      ng = m;
      // printf("ng=%d sum=%d m*k=%d\n", m, _sum(m), m*k);
    }
  }
  return ok;
}

signed main() {
  ll orig_N;
  {
    //orig_N=24;
    //N = 5;
    //a.push_back(1);
    //a.push_back(3);
    //a.push_back(5);
    //a.push_back(7);
    //a.push_back(8);
  }
  {
    map<ll,ll> mp;
    cin>>orig_N;
    rep(i,orig_N) {
      ll x;
      cin >> x;
      mp[x]++;
    }
    N = mp.size();
    for (auto e: mp) {
      a.push_back(e.second);
    }
  }

  sort(begin(a),end(a));
  psum.resize(a.size());
  psum[0] = a[0];
  for (ll i=1; i<N; i++) {
    psum[i] = psum[i-1] + a[i];
  }

  //cout << "N=" << N << " ";
  //cout << "a=";
  //rep(i,N){
  //  cout<<a[i]<<" ";
  //}
  //cout<<endl;

  //printf("sum(%d)=%d\n", 2, _sum(2));
  for (ll k=1; k<=orig_N; k++) {
    cout << solve(k) << endl;
  }
}
