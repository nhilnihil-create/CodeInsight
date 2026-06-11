#include <bits/stdc++.h>
#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
using namespace std;
using ll = long long;
using d = double;

int main(){
  int n;
  vector<int> a(9);
  rep(i,9) cin >> a[i];
  vector<int> b(n);
  cin >> n;
  rep(i,n) cin >> b[i];
  bitset<9> a2;
  rep(i,n)rep(j,9)if(b[i]==a[j])a2.set(8-j,1);
  bool y=0;
  if(a2.test(0)&&a2.test(1)&&a2.test(2)||a2.test(3)&&a2.test(4)&&a2.test(5)||a2.test(6)&&a2.test(7)&&a2.test(8)) y=1;
  if(a2.test(2)&&a2.test(5)&&a2.test(8)||a2.test(1)&&a2.test(4)&&a2.test(7)||a2.test(0)&&a2.test(3)&&a2.test(6)) y=1;
  if(a2.test(0)&&a2.test(4)&&a2.test(8)||a2.test(2)&&a2.test(4)&&a2.test(6)) y=1;
  
  if(y) cout << "Yes" << endl;
  else cout << "No" << endl;
  if(a[1]==1234)cout << a2;
  return 0;
}