#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <cmath>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <bitset>
#include <cstring>
#include <deque>
#include <iomanip>
#include <limits>
#include <fstream>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define MOD1 1000000007


int main() {
  ll N;
  cin >> N;
  string s;
  cin >> s;

  ll L = 1, R = -1;
  vector<ll> vec(2*N , 0);

  if(s.at(0) == 'W' || s.at(2*N -1) == 'W'){
    cout << 0 << endl;
    return 0;
  }

  vec.at(0) = L;

  rep(i, 2*N -1){
    if(s.at(i) == s.at(i+1)) 
      vec.at(i+1) = (-1) * vec.at(i);
    else 
      vec.at(i+1) = vec.at(i);
  }

  if(vec.at(2*N -1) != R){
    cout << 0 << endl;
    return 0;
  }

  vector<ll> right;

  rep(i,2*N){
    if(vec.at(i) == R) right.push_back(i);
  }

  if(right.size() != N){
    cout << 0 << endl;
    return 0;
  }

  vector<ll> NUM(N,0);
  rep(i,N){
    NUM.at(i) = right.at(i) - 2*i; 
  }

  ll ans = 1;

  rep(i,N){
    ll a = ((i+1) * NUM.at(i)) % MOD1;
    ans = (ans * a) % MOD1;
  }

  cout << ans << endl;


}