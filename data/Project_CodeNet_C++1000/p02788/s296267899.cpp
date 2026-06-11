#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;

long long MOD = 1000000000 + 7;

bool compare(pii x, pii y){
  return x.first < x.second;
}
int main(){
  cout << setprecision(10);

  ll N,D,A;
  cin >> N >> D >> A;

  vector<pii> v;
  for(int i = 0; i < N; i++){
    ll tmp1,tmp2;
    cin >> tmp1 >> tmp2;
    v.push_back(make_pair(tmp1, (tmp2+A-1)/A));
  }

  sort(v.begin(), v.end());
  auto tmp_last_monstar = v[v.size()-1];
  v.push_back(make_pair(tmp_last_monstar.first + 2*D + 2, 0));


  vector<ll> x(N);
  vector<ll> d(N+1,0);
  vector<ll> a(N);
  vector<ll> x_2D(N);
  for(int i = 0; i < N; i++){
    x[i] = v.at(i).first;
    a[i] = v.at(i).second;
  }

  for(int i = 0; i < N; i++){
    auto itr = lower_bound(x.begin(), x.end(), x[i] + 2*D+1);
    int index = itr - x.begin();
    x_2D[i] = index;
    // cerr << "D: " << D << " x[i]: " << x[i] << " x_2D[i]: " << x_2D[i] << endl;
  }

  ll ans = a[0];
  d[0] = a[0];
  d[x_2D[0]] -= a[0];
  for(int i = 1; i < N; i++){
    d[i] = d[i-1] + d[i];
    a[i] -= d[i];
    if(a[i] > 0){
      ans += a[i];
      d[i] += a[i];
      d[x_2D[i]] -= a[i];
    }
  }

  cout << ans << endl;
}
