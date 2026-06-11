#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
using P = pair<int, int>; 
using ll = long long;

int main()
{
  int n, k;
  cin >> n >> k;
  int sum = 0, tmp = 300, x;
  int a[n];
  rep(i, n){
    a[i] = k + i;
    sum += a[i];
  }
  rep(i, n){
    if(abs(a[i]) < tmp){
      tmp = abs(a[i]);
      x = i;
    }
  }
  cout << sum - a[x] << endl;
  return 0;
}