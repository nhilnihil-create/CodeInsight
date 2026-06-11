//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>
#include <iomanip>
#include <stdlib.h>
#include <queue>

using namespace std;

const int nmax = 1e9 + 7;
const long long INF = 1e18;
const double PI = 2 * asin(1);
typedef long long ll;


int main(){
  ll N; cin >> N;
  vector <ll> P(N);
  for (int i = 0; i < N; i++) cin >> P[i];

  vector <ll> loc(N + 1);
  for (int i = 0; i < N; i++){
    loc[P[i]] = i + 1;
  }

  vector <ll> checked;
  checked.push_back(0);
  checked.push_back(loc[N]);
  checked.push_back(N + 1);

  ll ans = 0;
  for (ll i = N - 1; i >= 1; i--){
    ll now = loc[i];
    ll L = 0, R = checked.size() - 1;

    ll here;
    while (true){
      here = (L + R) / 2;
      if (now < checked[here]) R = here;
      else L = here;
      
      if (here == (L + R) / 2) break;
    }
    here++;
    checked.insert(checked.begin() + here, now);

    ll cnt = 0;
    if (here - 2 >= 0){
      cnt += (checked[here - 1] - checked[here - 2]) * (checked[here + 1] - checked[here]);
    }

    if (here + 2 < checked.size()){
      cnt += (checked[here + 2] - checked[here + 1]) * (checked[here] - checked[here - 1]);
    }
    ans += cnt * i;
  }

  cout << ans << endl;
  return 0;
}
