#include <iostream>

using namespace std;

#define rep(i,n) for(int i=0; i<(int)(n); i++)

const int N = (int)1e6;

int main() {
  int n;
  cin >> n;
  int a[n];
  rep(i,n) cin >> a[i];
  sort(a, a+n);
  
  int p = 0, b[N+1];
  rep(i,N+1) b[i] = 0;
  rep(i,n) b[a[i]] += 1;
  rep(i,n) {
    if(p == a[i]) continue;
    p = a[i];
    rep(j,N-1) {
      int k = (j+2) * a[i];
      if(k > N) break;
      b[k] += 1;
    }
  }
  
  int s = 0;
  rep(i,n) if(b[a[i]] == 1) s += 1;
  cout << s << endl;
  return 0;
}