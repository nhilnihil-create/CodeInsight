#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>
#include <queue>
#include <string>
#define ll long long
using namespace std;
 
int main() {
  vector<ll> a;
  vector<ll> ps;
  int n; cin >> n;
  ll ps_sum = 0;
  for(int i=0; i<=n; i++){
    ll x; cin >> x;
    a.push_back(x);
    ps.push_back(ps_sum + x);
    ps_sum += x;
  }

  ll sum = 0;
  ll na = 1;
  for(int i=0; i<=n; i++){
    if(a[i]>na || (a[i]==na && i<n)){
      sum = -1;
      break;
    }
    na = min(na-a[i], ps[n]-ps[i]);
    sum += na + a[i];
    na *= 2;
  }

  cout << sum;
}