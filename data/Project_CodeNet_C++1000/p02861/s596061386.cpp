#include <bits/stdc++.h>
using namespace std;
typedef long double ll;

using pint = pair<ll, ll>;
int N;
vector<pint> v;

int main() {
  cin >> N;
  v.resize(N);
  for (int i = 0; i<N; i++){
    cin >> v[i].first >> v[i].second;
  }
  int P[N];
  for (int i = 1; i < N+1; i++) P[i-1] = i;
  ll total = 0;
  ll cnt = 0;
  do {
    for (int i = 0; i < N-1; i++){
      total += sqrt((v[P[i]-1].first - v[P[i + 1]-1].first) * (v[P[i]-1].first - v[P[i + 1]-1].first)+(v[P[i]-1].second - v[P[i + 1]-1].second)*(v[P[i]-1].second - v[P[i+1]-1].second));
    }
    cnt++;
  } while (next_permutation(P, P + N));
  //cout << total << ' ' << cnt <<endl;
  cout << fixed<<setprecision(6)<<total / cnt << endl;
  return 0;
}