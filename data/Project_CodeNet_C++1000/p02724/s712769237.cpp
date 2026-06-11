#include <bits/stdc++.h>
#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
using namespace std;
using ll = long long;
using d = double;

int main(){
  int x;
  cin >> x;
  ll hap = (x/500)*1000+x%500-(x%500%5);
  printf("%lld\n", hap);
  return 0;
}
