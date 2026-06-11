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

int f(string s){
  int n=s.length();
  vector<int> a(n);
  a[0] = n;
  int i = 1, j = 0;
  while(i<n){
    while (i+j<n && s[j]==s[i+j]) j++;
    a[i] = j;
    if (j==0) {
      i++;
      continue;
    }
    int k = 1;
    while(i+k<n && k+a[k]<j){
      a[i+k] = a[k];
      ++k;
    }
    i += k;
    j -= k;
  }

  int res = 0;
  rep(i,n){
    res = max(res,min(a[i],i));
  }
  return res;
}

int main() {
  int n; string s;
  cin >> n >> s;

  int ans = 0;
  rep(i,n) ans = max(ans,f(s.substr(i,n-i)));
  cout << ans << endl;
}
