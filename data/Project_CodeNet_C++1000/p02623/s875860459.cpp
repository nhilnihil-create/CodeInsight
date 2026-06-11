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
typedef long long ll;
using namespace std;

vector<ll> a, b, sa, sb;

int binarySearch(ll key) {
  int left = -1;
  int right = (int)sb.size();

  while (right-left>1) {
    int mid = left + (right-left) / 2;

    if (sb[mid]<=key) left = mid;
    else right = mid;
  }

  return left;
}

int main(int argc, char *argv[]) {
  int n, m, i;
  ll k;

  cin >> n >> m >> k;
  
  a.resize(n);
  sa.resize(n+1);
  b.resize(m);
  sb.resize(m+1);

  sa[0] = 0LL;
  sb[0] = 0LL;
  for(i=0;i<n;i++){
    cin >> a[i];
    sa[i+1] = sa[i] + a[i];
  }
  for(i=0;i<m;i++){
    cin >> b[i];
    sb[i+1] = sb[i] + b[i];
  }
  
  int ans = 0, tmp;
  for(i=0;i<=n;i++){
    if(sa[i]>k) continue;
    else{
      tmp = i + binarySearch(k-sa[i]);
      if(tmp>ans) ans = tmp;
    }
  }

  cout << ans << endl;

  return 0;
}
