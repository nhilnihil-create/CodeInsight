#include <iostream>
#include <iomanip>

using namespace std;

#define rep(i,n) for(int i=0; i<(int)(n); i++)

int main() {
  int n, k;
  cin >> n >> k;
  int p[n];
  rep(i,n) cin >> p[i];
  
  int a[n];
  rep(i,n) a[i] = p[i] + 1;
  
  int s[n+1];
  s[0] = 0;
  rep(i,k) s[i+1] = s[i] + a[i];
  rep(i,n-k) s[i+k+1] = s[i+k] + a[i+k] - a[i];
  
  int m = 0;
  rep(i,n+1) if(s[i] > m) m = s[i];
  
  cout << fixed << setprecision(1) << (double)m / 2 << endl;
  return 0;
}