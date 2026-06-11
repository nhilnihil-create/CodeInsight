#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define repr(i, n) for(int i = n; i >= 0; i--)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
int main()
{
  int n;
  cin >> n;
  vector<ll> vec(n);
  ll m = vec[0];
  rep(i, n) {
    cin >> vec[i];
  }
  rep(i, n-1) {
    if (vec[i+1] > vec[i]) {
      vec[i+1]--;
      m = max(m, vec[i+1]);
    }
    if (vec[i+1] < vec[i]) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  
  return 0;
}