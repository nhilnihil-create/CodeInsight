//g++ -std=gnu++14 a.cpp

#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <iostream>
#include <istream>
#include <iterator>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <tuple>
#include <iomanip>
#include <random>
#include <math.h>
#include <stdio.h>

using namespace std;

#define ll long long
#define rep(i, n) for(ll i = 0; i < (n); i++)
ll MOD = 1e9 + 7;
int INF = 1 << 30;
ll INFL = 1LL << 60;
ll MODP = 998244353;

int main(){
  ll N;
  cin >> N;
  vector<ll> A(N);
  rep(i,N)cin >> A[i];
  ll ans = 0;
  rep(i,70){
    ll a = 0, b = 0;
    rep(j,N){
      if(A[j]%2 == 0){
        a++;
        A[j] = A[j] >> 1;
      }else{
        b++;
        A[j] = A[j] >> 1;
      }
    }
    ll k = 1;
    rep(a,i){
      k *= 2;
      k %= MOD;
    }
    ans = ( ans%MOD + ( (((a%MOD)*(b%MOD))%MOD) * k )%MOD )%MOD;
  }
  cout << ans << endl;
}
