#include <bits/stdc++.h>
using namespace std;
using P = pair<int, int>;
using ll = long long;

int main(){
  int n;
  cin >> n;
  map<P,int> mp;
  for(int i=1; i<=n; ++i){
    int a, b;
    a = i%10;
    b = i;
    while(b>=10) b /= 10;
    mp[make_pair(a,b)]++;
  }
  ll ans=0;
  for(auto pi: mp){
    int a, b;
    a = pi.first.first;
    b = pi.first.second;
    ans += (ll)pi.second * (ll)mp[make_pair(b,a)];
  }
  cout << ans << endl;
}
