#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
#define rep(i,n) for(int i = 0; i < n; i++)
 
int main() {
  int N,M;
  cin >> N >> M;
  vector<int> a(N);
  ll s = 0;
  int cnt = 0;
  rep(i,N) {
    cin >> a[i];
    s += a[i];
  }
  rep(i,N) {
    if (4*a[i]*M >= s) cnt++;
  }
  if (cnt >= M) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
  return 0;
}