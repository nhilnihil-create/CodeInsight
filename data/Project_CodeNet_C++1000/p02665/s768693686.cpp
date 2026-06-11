#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <climits>
#include <utility>
#include <numeric>
typedef long long ll;
using namespace std;

int main(void){
  const ll BIG = 1LL << 60;

  int n, i;
  cin >> n;
  n++;

  if(n==1){
    ll x;
    cin >> x;
    if(x==1){
      cout << 1 << endl;
    }
    else{
      cout << -1 << endl;
    }
    return 0;
  }

  vector<ll> a(n), max(n);
  for(i=0;i<n;i++){
    cin >> a[i];
  }

  max[0] = 1;
  if(a[0]!=0){
    cout << -1 << endl;
    return 0;
  }
  for(i=1;i<n-1;i++){
    max[i] = max[i-1] * 2 - a[i];
    if(max[i]<1){
      cout << -1 << endl;
      return 0;
    }
    if(max[i]>BIG) max[i] = BIG;
  }
  max[n-1] = max[n-2] * 2 - a[n-1];
  if(max[n-1]<0){
    cout << -1 << endl;
    return 0;
  }

  ll tmp = a[n-1], ans = a[n-1];
  for(i=n-2;i>0;i--){
    if(max[i]<tmp){
      tmp = max[i] + a[i];
      ans += tmp;
    }
    else{
      tmp = tmp + a[i];
      ans += tmp;
    }
  }
  ans++;

  cout << ans << endl;

  return 0;
}
