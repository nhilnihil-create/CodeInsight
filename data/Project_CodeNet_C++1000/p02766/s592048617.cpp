#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using ll = long long;

int main() {
  int N,K;
  cin >> N >> K;
  int ans=0;
  int x = N;
  while(x>=K) {
    ans++;
    x /= K;
  }
  cout << ans+1 << endl;
}