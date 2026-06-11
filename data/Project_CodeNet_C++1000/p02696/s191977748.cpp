#include <bits/stdc++.h>
#include <vector>
#define rep(i, n) for(ll int i = 0; i < n; ++i)
#define ll long long
using namespace std;

int main() {
  ll int a, b, n;
  cin >> a >> b >> n;
  
  ll int k;
  if(b <= n) k = n - (n % b) - 1;
  else k = n;
  
  ll int answer = ((a * k) / b) - (a * (k / b));
  cout << answer << endl;
  return 0;
}
