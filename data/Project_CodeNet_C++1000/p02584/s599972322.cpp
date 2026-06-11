#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <math.h>
#include <cassert>
#define rep(i,n) for(int i = 0; i < n; ++i )
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  ll x,k,d;
  cin >> x >> k >> d;
  x = abs(x);
  if(k<x/d){
    x -= k*d;
  }else{
    k -= x/d;
    x %= d;
    x = k&1 ? d-x : x;
  }
  cout << x << endl;
}
