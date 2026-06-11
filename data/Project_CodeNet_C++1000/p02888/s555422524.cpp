#include <bits/stdc++.h>
#include <boost/integer/common_factor_rt.hpp>
using namespace std;
using ll=long long;
const int MOD=1000000007;


int main() {
  int n;
  cin >> n;
  vector<int> l(n);
  for(int i=0;i<n;i++){
    cin >> l.at(i);
  }
  sort(l.begin(),l.end());
  ll ans=0;
  for(int i=0;i<n-2;i++){
    for(int j=i+1;j<n-1;j++){
      for(int k=j+1;k<n;k++){
        if(l[i]+l[j]>l[k])
        ans++;
        else
        break;
      }
    }
  }
  cout << ans << endl;
}