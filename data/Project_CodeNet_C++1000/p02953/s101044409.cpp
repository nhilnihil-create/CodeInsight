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
  bool ans=true;
  
  rep (i, n-1) {
    if(h.at(n-1-i)<h.at(n-i-2)-1) {
      ans = false;
      break;
    }
    else if(h.at(n-i-1) == h.at(n-i-2)-1){
      h.at(n-i-2)--;
    }
  }
  if(ans) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}