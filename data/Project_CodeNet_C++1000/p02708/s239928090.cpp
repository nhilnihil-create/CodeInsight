#include <bits/stdc++.h>
using namespace std;

long f(long i, long n, long m){
  long r = (n+1) * i - i*i + 1;
  return r % m;
}


int main(){
  long n, k;  cin >> n >> k;
  long m = 1e9+7, ans = 0;
  for(long i=k; i<=n+1; i++){
    ans = (ans + f(i, n, m)) % m;
  }

  cout << ans << endl;

  return 0;
}
