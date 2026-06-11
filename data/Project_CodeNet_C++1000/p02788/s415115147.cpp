#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);cout.tie(0);

  ll n, d, a;
  cin >> n >> d >> a;
  vector < pair < ll, ll > > v;
  for(int i = 0; i < n; i++){
    ll x, h;
    cin >> x >> h;
    v.push_back({x, (h + a - 1) / a});
  }
  sort(v.begin(), v.end());

  vector < ll > p(n + 2, 0);
  ll bombs = 0, rt;
  for(int i = 0; i < n; i++){
    ll x = v[i].first, req = v[i].second;
    req -= p[i];
    if(req <= 0){
      p[i + 1] += p[i];
      continue;
    }
    bombs += req;
    ll lo = i, hi = n - 1;
    while(lo <= hi){
      ll mid = (hi - lo) / 2 + lo;
      if(v[mid].first <= x + 2 * d){
        lo = mid + 1;
        rt = mid;
      }
      else hi = mid - 1;
    }
    p[rt + 1] -= req;
    p[i] += req;
    p[i + 1] += p[i];
  }

  cout << bombs << endl;
}
