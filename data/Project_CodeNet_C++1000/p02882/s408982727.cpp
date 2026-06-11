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
  int a,b,x;
  cin >> a >> b >> x;
  int all = a*a*b;
  if(x*2 > all){
    double less = all - x;
    double c = less*2 / double(a*a);
    cout << fixed << setprecision(8) << 180.0*atan(double(c)/double(a))/acos(-1) << endl;
  }else{
    double d = double(x*2) / double(a*b);
    cout << fixed << setprecision(8) << 180.0*atan(double(b)/double(d))/acos(-1) << endl;
  }


  return 0;
}
