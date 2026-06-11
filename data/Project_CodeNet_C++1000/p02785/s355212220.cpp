#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
using P = pair<int, int>; 
using ll = long long;

int main()
{
  int n;
  cin >> n;
  int k;
  cin >> k;
  int a[n];
  ll sum = 0;
  rep(i, n){
    cin >> a[i];
    sum += a[i];
  }
  int ans = 0;
  sort(a, a + n, greater<>());
  rep(i, k) {
    sum -= a[i];
    if(i + 1 == n) break;
  }
  if(sum < 0) sum = 0;
  cout << sum << endl;

  return 0;
}