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
  vector<ll>  num(N+10),nummin(N+10,INFL);
  for(int i = 1;i <= N;i++)cin >> num[i];
  for(int i = 1;i <= N;i++){
    if(num[i] < nummin[i-1])nummin[i] = num[i];
    else nummin[i] = nummin[i-1];
  }
  ll ans = 0;
  for(int i = 1;i <= N;i++){
    if(nummin[i] >= num[i])ans++;
  }
  cout << ans << endl;
  return 0;
}
