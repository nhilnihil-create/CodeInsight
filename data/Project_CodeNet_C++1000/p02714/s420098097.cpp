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
  string S;
  cin >> S;
  if(N < 3){
    cout << 0 << endl;
    return 0;
  }
  vector<ll> cnt(3,0);
  rep(i,S.size()){
    if(S.at(i) == 'R')cnt[0]++;
    if(S.at(i) == 'G')cnt[1]++;
    if(S.at(i) == 'B')cnt[2]++;
  }
  ll all = cnt[0]*cnt[1]*cnt[2];

  for(int i = 2;i <= N-1;i += 2){
    for(int j = 0;j <= S.size()-1-i;j++){
      if(S.at(j) != S.at(j+i/2) && S.at(j) != S.at(j+i) && S.at(j+i/2) != S.at(j+i))all--;
    }
  }

  cout << all <<  endl;



  return 0;
}
