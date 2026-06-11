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
  string s;
  cin >> s;
  vector<string> today = {"MON","TUE","WED","THU","FRI","SAT","SUN"};
  rep(i,7){
    if(today[i] == s){
      int ans = 6 - i;
      if(ans == 0)ans = 7;
      cout << ans << endl;
      break;
    }
  }
  return 0;
}
