#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {

  ll n; cin >> n;
  ll arr[n] = {0};
  for(ll i = 1; i <= n; ++i){
    cin >> arr[i];
    if(i % 2 == 0) arr[i] += arr[i - 1];
    else arr[i] = arr[i - 1] - arr[i];
  }
  for(ll i = 1; i <= n; ++i){
    if(i % 2 == 0){
        cout << abs(2 * arr[i - 1] - arr[n]) << " ";
    }
    else cout << abs(arr[n] - 2 * arr[i - 1]) << " ";
  }
  return 0;
}
