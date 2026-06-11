#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n, d;
  cin >> n >> d;
  
  ll a, b;
  int cnt = 0;
  for(int i=0; i<n; i++) {
    cin >> a >> b;
    if(sqrt(a*a+b*b)<=d) cnt++;
  }
  
  cout << cnt << endl;
  return 0;
}