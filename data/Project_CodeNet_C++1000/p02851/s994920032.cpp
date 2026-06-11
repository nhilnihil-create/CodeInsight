#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <iomanip>
#include <utility>
#include <tuple>
#include <functional>
#include <bitset>
#include <cassert>
#include <complex>
#include <stdio.h>
#include <time.h>
#include <numeric>
#include <random>
#include <unordered_map>
#include <unordered_set>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
#define rep(i,n) for(ll i = 0;i < (ll)n;i++)
#define ALL(x) (x).begin(),(x).end()
#define MOD 1000000007



int main(){
  
  ll n,K;
  cin >> n >> K;
  vector<ll> s(n+1,0);
  map<ll,ll> r;
  r[0] = 1;
  ll res = 0;
  rep(i,n){
    if(i-K+1 >= 0)r[s[i-K+1]]--;
    ll x;cin >> x;
    s[i+1] = (s[i]+x-1)%K;
    res += r[s[i+1]];
    r[s[i+1]]++;
  }
  cout << res << "\n";
  

  return 0;
}