#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;

int p = 1000000007;

int main(){
  int n, m;
  cin >> n >> m;
  vector<bool> a(n+1, true);
  for(int i = 0; i < m; i++){
    int A;
    cin >> A;
    a[A] = false;
  }
  
  vector<i64> sum(100010);
  for(int i = 0; i < sum.size(); i++)
    sum[i] = 0;
  sum[0] = 1;
  if(a[1])
    sum[1] = 1;
  
  for(int i = 2; i <= n; i++){
    if(a[i])
      sum[i] = (sum[i-1] + sum[i-2])%p;
  }
  
  cout << sum[n] << endl;
  
  return 0;
  
}