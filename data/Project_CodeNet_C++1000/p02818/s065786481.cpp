#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <cmath>
#include <map>
#include <queue>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long

int main() {
  ll a, b, k;
  cin >> a >> b >> k;
  if(k <= a) {printf("%lld %lld\n",a-k, b);}
  else {
    k = k - a;
    if(k <= b) {printf("%lld %lld\n",0, b-k);}
    else {printf("%d %d\n",0,0);}
  }
}