#include <bits/stdc++.h>

#define rep(i, n) for (ll i = 0; i < (n); i++)
#define rep2(i, a, b) for (ll i = (a); i < (b); i++)
typedef uint64_t ull;
typedef int64_t ll;
typedef std::pair<ll, ll> PLL;

using namespace std;

signed main() {
  const ll T = 100000000;
  ll N;
  cin >> N;
  vector<ll> x(N), y(N);
  rep(i,N)
    cin >> x[i] >> y[i];
  //ll N=100;
  //vector<ll> x(N), y(N);
  //rep(i,N)
  //  x[i]=y[i]=1000000;


  vector<double> cx, cy; // candinate
  rep(i,N) {
    rep(j,N) {
      cx.push_back(x[i] + x[j]);
      cy.push_back(y[i] + y[j]);
    }
  }

  //cout<<"can:"<<endl;
  //rep(i, cx.size()){
  //  cout<<cx[i] << " " << cy[i]<<endl;
  //}

  ll ans = 0;
  rep(i, cx.size()){
    ll curx = 0, cury = 0;
    rep(j, N) {
      if (cx[i]*x[j] + cy[i]*y[j] > 0) { // 90度未満
        curx += x[j];
        cury += y[j];
      }
    }
    ans = max(ans, curx * curx + cury * cury);
  }
  printf("%.20f\n", sqrt(ans));
  return 0;
}
