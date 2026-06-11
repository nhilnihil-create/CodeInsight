#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <climits>
#include <iomanip>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
ll mod = 998244353;
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
int main(){
  ll n = 0;
  cin >> n;
  ll res = 0;
  res = 1;
  vector<ll> count(n);
  for(int i = 0;i < n;i++){
    ll in;
    cin >> in;
    count[in]++;
    if((i == 0 && in != 0) || (i != 0 && in == 0)){
      cout << 0 << endl;
      return 0;
    }
  }
  for(int i = 1;i < n;i++){
    if(count[i] > 0){
      res *= power(count[i - 1],count[i]);
      res %= mod;
    }
  }
  if(n == 1){
    if(count[0] == 1)res = 1;
    else res = 0;
  }
  if(count[0] != 1)res = 0;
  cout << res << endl;
}