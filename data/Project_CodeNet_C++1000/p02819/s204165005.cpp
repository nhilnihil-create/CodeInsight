#include <bits/stdc++.h>
#include <cstdlib>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll = long long;

bool is_prime(long long N) {
    if (N == 1) return false;
    for (long long i = 2; i * i <= N; ++i) {
        if (N % i == 0) return false;
    }
    return true;
}

int main(){
  ll X;
  cin >> X;
  ll ans = X;
  while(!(is_prime(ans))){
    ans++;
  }
  
  cout << ans << endl;
  
  return 0;
}