#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;cin>>n;
  int v[n]; for(int i=0;i<n;i++)cin>>v[i];
  ll ans = 0;
  for (int i=0;i<n-1;i++){
    for (int j=i+1;j<n;j++){
      ans += v[i] * v[j];
    }
  }
  cout << ans << endl;
}