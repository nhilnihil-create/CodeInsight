#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <climits>
#include <iomanip>
#include <set>
using namespace std;
typedef long long ll;
long long mod = 1000000007;
long long power(long long m,long long n){
    long long res = 1;
    if(n > 0){
        res = power(m,n / 2);
        if(n % 2 == 0){
            res = (res * res) % mod;
        }
        else{
            res = (((res * res) % mod) * m) % mod;
        }
    }
    return res;
}
//modはグローバル変数にしておく
int main(){
  ll n,k;
  cin >> n >> k;
  vector<ll> count(k + 1);
  ll res = 0;
  for(int i = k;i >= 1;i--){
    int kazu = 0;
    kazu = k / i;
    count[i] = power((ll)kazu,n);
    for(int j = 2;j <= kazu;j++){
      count[i] -= count[j * i];
      if(count[i] < 0)count[i] += mod;
    }
    res += count[i] * i;
    res %= mod;
    //cout << kazu << " " << count[i] << endl;
  }
  cout << res << endl;
  return 0;
}