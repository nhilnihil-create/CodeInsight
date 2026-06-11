#include <bits/stdc++.h>
using namespace std;
using int64 = long long;


int64 C(int64 n){
  return n * (n - 1) / 2;
}

int main(){
  int n;
  cin >> n;
  vector<int> a(n), c(n);
  for(int i = 0; i < n; ++i){
    cin >> a[i];
    --a[i];
    c[a[i]]++;
  }
  int64 sum = 0;
  for(int i = 0; i < n; ++i){
    sum += C(c[i]);
  }
  for(int i = 0; i < n; ++i){
    cout << sum - C(c[a[i]]) + C(c[a[i]] - 1) << endl;
  }
}