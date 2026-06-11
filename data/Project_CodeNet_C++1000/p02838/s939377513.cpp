#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 1000000000+7;

int main(){
  int n;
  cin >> n;
  vector<ll> a(n);
  for(int i=0;i<n;i++) cin >> a[i];

  ll sum = 0;
  ll place = 1;
  for(int bit=0;bit<62;bit++){
    int one=0,zero=0;
    for(int i=0;i<n;i++){
      if(a[i]>>bit & 1 == 1){
        one++;
      }else{
        zero++;
      }
    }
    sum += place * one % MOD * zero;
    sum %= MOD;
    place *= 2;
    place %= MOD;
  }

  cout << sum << endl;
}
