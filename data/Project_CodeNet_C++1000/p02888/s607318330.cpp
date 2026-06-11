#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
  int N;
  cin >> N;
  
  vector<ll> L(1010, 0);
  
  for (int i = 0; i < N; i++) {
    ll l;
    cin >> l;
    L[l]++;
  }
  
  vector<ll> sum(1010, 0);
  
  for (int i = 0; i < 1000; i++) {
    sum[i+1] = sum[i] + L[i+1];
  }
  
  ll ans = 0;
  for (int i = 1; i <= 1000; i++) {
    if (L[i] == 0) continue;
      
    for (int j = i; j <= 1000; j++) {
      if (L[j] == 0) continue;
      
      if (i == j) {
        ans += ((L[i] * (L[i]-1) / 2) * (sum[min(1000, 2*i-1)] - sum[i]) );
        ans += L[i] * (L[i]-1) * (L[i]-2) / 6;
      } else {
        ans += (L[i] * L[j] * (sum[min(1000, i+j-1)] - sum[j]));
        ans += L[i] * L[j] * (L[j]-1) / 2;
      }
    }
  }
  
  
  cout << ans << endl;
  
}