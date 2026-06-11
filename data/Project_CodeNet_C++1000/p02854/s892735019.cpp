#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
const long long mod = 1e9+7;
//////////////////////////////////

int main() {
  int n; cin >> n;
  long long sum = 0;
  vector<long long> a(n);
  for(int i=0; i<n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  long long ans = 1e15;
  long long l = 0;
  for(int i=0; i<n; i++) {
    l += a[i];
    long long r = sum - l;
    ans = min(ans, abs(l-r));
  }
  cout << ans << endl;

  return 0;
}

// EOF
