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

int main(){
  ll N,K;
  cin >> N >> K;
  vector<ll> p(N);
  rep(i,N)cin >> p[i];
  vector<double> q(N);
  rep(i,N)q[i] = double(1 + p[i])/double(2);
  double max = 0.0;
  rep(i,K)max += q[i];
  double ans = max;
  rep(i,N-K){
    max -= q[i];
    max += q[i+K];
    if(max > ans)ans = max;
    //cout << ans << endl;
  }
  cout << fixed << setprecision(10) << ans << endl;
}
