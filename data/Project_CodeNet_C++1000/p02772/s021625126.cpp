//g++ -std=gnu++14 a.cpp
//#include <bits/stdc++.h>

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

using namespace std;

#define ll long long
#define rep(i, n) for(ll i = 0; i < (n); i++)
ll MOD = 1e9 + 7;
int INF = 1 << 30;
ll INFL = 1LL << 60;

int main(){
  ll N;
  cin >> N;
  vector<ll> V(N);
  rep(i,N)cin >> V[i];
  bool flag = true;
  rep(i,N){
    if(V[i]%2==0){
      if(V[i]%3!=0 && V[i]%5!=0){
        flag = false;
        break;
      }
    }
  }
  if(flag)cout << "APPROVED" << endl;
  else cout << "DENIED" << endl;
}
