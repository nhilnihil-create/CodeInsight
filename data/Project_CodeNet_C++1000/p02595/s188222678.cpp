#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  using pint = pair<ll, ll>;
  ll N, D;
  cin >> N >> D;
  vector<pint> v(N);
  for (int i = 0; i < N; ++i)cin >> v[i].first >>v[i].second;
  ll cnt = 0;
  for (int i = 0; i< N; i++){
    if (v[i].first * v[i].first + v[i].second * v[i].second <= D * D) cnt++;
  }
  cout << cnt << endl;
  return 0;
}