#include <iostream>

using namespace std;

typedef long long ll;

const int MAX_N = 2e5 + 5;

ll arr [MAX_N];

int main () {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    arr[i] *= 2;
  }

  for (int i = 1; i < n; i++) {
    arr[i] += arr[i - 1];
  }

  ll targ = arr[n - 1] / 2;
  ll ans = targ;
  for (int i = 0; i < n; i++) {
    ans = min(ans, abs(arr[i] - targ));
  }
  cout << ans << endl;
}
