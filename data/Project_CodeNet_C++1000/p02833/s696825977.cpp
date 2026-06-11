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
  if(N&1){
    cout << 0 << endl;
  }else{
    ll ni = 0 , go = 0;
    ll waruni = 2 , warugo = 10;
    while(waruni <= N){
      ni += N/waruni;
      waruni *= 2;
    }
    while(warugo <= N){
      go += N/warugo;
      warugo *= 5;
    }
    ll ans = ni;
    if(ans > go)ans = go;
    cout << ans << endl;


  }
}
