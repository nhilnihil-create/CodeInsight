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

ll gen(ll x,ll y){
  if(y == 0)return 1;
  if(y == 1)return x%MODP;
  if(y%2 == 1){
    return ((x%MODP)*(gen(x,y-1))%MODP)%MODP;
  }else{
    ll t = gen(x,y/2);
    return ((t%MODP)*(t%MODP))%MODP;
  }
}

ll comb(ll x,ll y){
  if(y == 0)return 1;
  ll res = 1;
  rep(i,y){
    res = ((res%MODP)*((x-i)%MODP))%MODP;
  }
  for(ll i = 1;i <= y;i++){
    res = ((res%MODP)*gen(i,MODP-2))%MODP;
  }
  return res%MODP;
}

int main(){
  ll a,b;
  cin >> a >> b;
  if(a == b){
    string s = "";
    rep(i,b)s += to_string(b);
    cout << s << endl;
  }else if(a < b){
    string s = "";
    rep(i,b)s += to_string(a);
    cout << s << endl;
  }else{
    string s = "";
    rep(i,a)s += to_string(b);
    cout << s << endl;
  }


  return 0;
}
