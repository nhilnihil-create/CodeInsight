#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int main(){
  ll n;
  cin >> n;
  vector<ll> h(n);
  rep(i,n){
    cin >> h.at(i);
  }
  string ans="Yes";
  ll maxi=0;
  rep(i,n){
    maxi=max(maxi,h.at(i));
    if(maxi>h.at(i)+1){
      ans="No";
    }
  }
  cout << ans;
}
    
    