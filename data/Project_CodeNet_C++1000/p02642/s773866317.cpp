#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll kanta[2000111];

int main() {

  ll n; cin >> n;
  ll arr[n] = {0}, ans = 0;
  for(ll i = 0; i < n; ++i){
    cin >> arr[i];
    kanta[arr[i]]++;
  }
  sort(arr, arr + n);
  for(ll i = 0; i < n; ++i){
    ll cur = arr[i], tmp = arr[i];
    if(kanta[cur] == 1)ans++;
    if(kanta[cur] == 0)continue;
    while(cur < 2000024){
        kanta[cur] = 0;
        cur += tmp;
    }
    cur = 0;
  }
  cout << ans;
  return 0;
}
