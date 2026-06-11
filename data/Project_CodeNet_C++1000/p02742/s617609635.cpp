#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll zero = 0;
const ll INF = 10000000000000000; //10^16
const ll MOD = 1000000007; //10^9+7
const ll MOD2 = 998244353;
 
int main(){
  ll H,W; cin >> H >> W;
  if(H == 1 || W == 1){
    cout << 1 << endl;
    return 0;
  }
  printf("%lld\n", (H*W+1)/2);
  return 0;
}