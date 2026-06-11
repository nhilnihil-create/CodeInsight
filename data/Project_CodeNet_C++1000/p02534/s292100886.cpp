
#include <bits/stdc++.h>
#define rep(i,n) for (ll i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
const ll INF=1e18;

int main() {
  int k;
  cin>>k;
  string s="ACL";
  rep(i,k-1){
    s+="ACL";
  }
  cout<<s;
}
