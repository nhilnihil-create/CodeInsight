#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int n;
  cin>>n;
  vector<ll> h(n);
  rep (i, n) {
    cin>>h.at(i);
  }
  int ans=0;
  int memo=0;
  rep (i, n-1) {
    if(h.at(i)>=h.at(i+1)) {
      memo++;
      ans=max(memo, ans);
    }
    else {
      memo=0;
    }
  }
  cout<<ans<<endl;
  
}