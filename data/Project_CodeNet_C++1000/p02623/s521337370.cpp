#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n, m, k;
  cin >> n >> m >> k;
  
  ll sum = 0, num = 0;
  int x, ans = 0;
  string s;
  vector<int> a, b;
  for(int i=0; i<n; i++) {
    cin >> x;
    a.push_back(x);
    sum += x;
    if(sum>k) {
      ans = i;
      num = sum-x;
      a.pop_back();
      getline(cin, s);
      break;
    }
    if(i==n-1) {
      ans = i+1;
      num = sum;
    }
  }
  
  sum = 0;
  for(int i=0; i<m; i++) {
    cin >> x;
    b.push_back(x);
    sum += x;
    if(sum>k) {
      if(ans<i) {
        ans = i;
        num = sum-x;
      }
      b.pop_back();
      getline(cin, s);
      break;
    }
    if(i==m-1 && ans<i+1) {
      ans = i+1;
      num = sum;
    }
  }
  
  int c = 0;
  ll d = 0;
  bool check = false;
  if(a.size()>=b.size()) {
    for(int i=a.size(); i>=0; i--) {
      if(i!=a.size()) num -= a[i];
      ll t = num;
      for(int j=c; j<b.size(); j++) {
        if(j==c) t += d;
        t += b[j];
        if(t>k) {
          ans = max(ans, i+j);
          c = j;
          d = t-b[j]-num;
          break;
        }
        if(j==b.size()-1) {
          ans = max(ans, i+j+1);
          check = true;
        }
      }
      if(check) break;
    }
  }
  
  else {
    for(int i=b.size(); i>=0; i--) {
      if(i!=b.size()) num -= b[i];
      ll t = num;
      for(int j=c; j<a.size(); j++) {
        if(j==c) t += d;
        t += a[j];
        if(t>k) {
          ans = max(ans, i+j);
          c = j;
          d = t-a[j]-num;
          break;
        }
        if(j==a.size()-1) {
          ans = max(ans, i+j+1);
          check = true;
        }
      }
      if(check) break;
    }
  }
  
  cout << ans << endl;
  return 0;
}