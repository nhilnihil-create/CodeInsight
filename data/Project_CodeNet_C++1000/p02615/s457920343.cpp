#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; ++i)
using namespace std;

int main(){
  int n;
  cin >> n;
  long a = 0;
  vector<int> v(n);
  rep(i, n) cin >> v[i];
  sort(v.begin(), v.end());
  reverse(v.begin(), v.end());
  rep(i, n-1) a += v[(i+1)/2];
  cout << a << endl;
  return 0;
}