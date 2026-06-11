#include <iostream>

using namespace std;

typedef long long ll;

#define rep(i,n) for(ll i=0; i<(ll)(n); i++)

const int N = (int)1e6;

int main() {
  ll n;
  cin >> n;
  int c[N];
  rep(i,N) c[i] = 0;
  
  rep(i,N) {
    while(i >= 2 && n % i == 0) {
      n = n / i;
      c[i]++;
    }
  }
  
  int s = 0;
  if(n != 1) s += 1;
  rep(i,N) {
    int j = 0;
    for(; c[i] >= j * (j + 1) / 2; j++);
    s += j - 1;
  }
  cout << s << endl;
  return 0;
}