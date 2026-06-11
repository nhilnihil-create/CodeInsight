#include <iostream>

using namespace std;

#define rep(i,n) for(int i=0; i<(int)(n); i++)

typedef long long ll;

int main() {
  int n;
  ll k;
  cin >> n >> k;
  int a[n], b[n];
  rep(i,n) cin >> a[i];
  rep(i,n) b[i] = -1;
  
  int t = 1, l = 0, s;
  while(b[t-1] == -1) {
    b[t-1] = l;
    t = a[t-1];
    l++;
  }
  s = b[t-1];
  l = l - s;
  
  if(k > s) {
    k = (k - s) % l;
  } else {
    t = 1;
  }
  
  for(; k > 0; k--) t = a[t-1];
  cout << t << endl;
  return 0; 
}