#include <iostream>

using namespace std;

#define int long long
#define rep(i,n) for(int i=0; i<(int)(n); i++)

const int N = (int)2e5;

signed main() {
  int n;
  cin >> n;
  int a[n];
  rep(i,n) cin >> a[i], a[i]--;
  
  int r[N];
  rep(i,N) r[i] = 0;
  rep(i,n) r[a[i]]++;
  
  int s = 0;
  rep(i,N) s += r[i] * (r[i] - 1) / 2;
  rep(i,n) cout << s - r[a[i]] + 1 << endl;
  return 0;
}