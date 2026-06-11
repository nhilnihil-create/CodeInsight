#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, k, a[1010], sum = 0;
  cin >> n >> k;
  for(int i=1; i<=n; i++) cin >> a[i];
  sort(a+1, a+n+1);
  for(int i=1; i<=k; i++) sum += a[i];
  cout << sum;
}