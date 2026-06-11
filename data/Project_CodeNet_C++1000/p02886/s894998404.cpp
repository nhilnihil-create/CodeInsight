#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1000000007;

int main() {
 int n;
  cin >> n;
  vector<int> a(n);
  for(int i=0;i<n;i++){
    cin >> a.at(i);
  }
  ll ans=0;
  for(int i=0;i<n-1;i++){
    for(int j=i+1;j<n;j++){
      ans=ans+a.at(i)*a.at(j);
    }
  }
  cout << ans << endl;
}

