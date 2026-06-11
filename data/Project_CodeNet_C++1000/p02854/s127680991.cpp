#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  int n;
  cin >> n;
  vector<int> an(n);
  ll tot = 0;
  for(int i=0; i<n; ++i){
    cin >> an[i];
    tot += an[i];
  }
  ll ans = tot;
  ll tot2 = 0;
  for(int i=0; i<n-1; ++i){
    tot2 += an[i];
    ans = min(ans, abs(tot -tot2*2));
  }
  cout << ans << endl;
}