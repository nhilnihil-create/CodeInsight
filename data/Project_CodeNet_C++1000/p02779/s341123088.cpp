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
  ll n;
  cin >> n;
  vector<ll> A(n);
  rep(i,n)cin >> A[i];
  sort(A.begin(),A.end());
  ll cnt = 0;
  rep(i,n-1)if(A[i] == A[i+1])cnt++;
  if(cnt==0)cout << "YES" << endl;
  else cout << "NO" << endl;
}
