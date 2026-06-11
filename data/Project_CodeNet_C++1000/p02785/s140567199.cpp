#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  int n,k;
  cin >> n >> k;
  vector<int> h(n);
  for(int i=0;i<n;i++){
    cin >> h.at(i);
  }
  sort(h.begin(),h.end());
  reverse(h.begin(),h.end());
  ll ans=0;
  for(int i=k;i<n;i++){
    ans += h.at(i);
  }
  
  cout << ans << endl;
  
  return(0);
}