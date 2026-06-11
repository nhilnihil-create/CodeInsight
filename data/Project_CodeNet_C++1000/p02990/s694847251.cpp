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
  vector<ll> factorial(3000);
  factorial[0] = 1;
  factorial[1] = 1;
  for(int i = 2;i < 3000;i++)factorial[i] = factorial[i - 1] * i,factorial[i] %= mod;
  for(int i = 1;i <= k;i++){
    ll res = 0;
    res = 1;
    if(n - k + 1 < i)res = 0;
    else{
    res *= factorial[n - k + 1],res %= mod;
    //if(i == 50)cout<<res<<endl;
    res *= power(factorial[i],mod - 2),res %= mod;
      //if(i == 50)cout<<res<<endl;
    res *= power(factorial[n - k + 1 - i],mod - 2),res %= mod;
      //if(i == 50)cout<<res<<endl;
    res *= factorial[k - 1],res %= mod;
      //if(i == 50)cout<<res<<endl;
    res *= power(factorial[i - 1],mod - 2),res %= mod;
      //if(i == 50)cout<<res<<endl;
    res *= power(factorial[k - i],mod - 2),res %= mod;
    }
    cout << res << endl;
  }
  return 0;
}
