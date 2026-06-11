
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
  int n;
  cin >> n;
  vector<ll> comfort;

  for (int i=0; i<n; i++) {
    ll a;
    cin >> a;
    comfort.push_back(a);
  }

  sort(comfort.begin(), comfort.end(), greater<ll>());

  ll ans = 0;
  for (int i=1; i<n/2; i++) {
    ans += comfort[i];
  }
  ans *= 2;
  ans += comfort[0];

  if (n%2 == 1) {
    ans += comfort[n/2];
  }

  cout << ans << endl;
}