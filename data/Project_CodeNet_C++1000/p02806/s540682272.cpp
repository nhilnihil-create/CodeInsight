#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0;i<n;i++)
#define cY cout << "Yes" << endl;
#define cN cout << "No" << endl;
    
int main() {
  ll n;string x;
  cin >> n;
  vector<string>s(n);
  vector<ll>t(n);
  rep(i,n) cin >> s.at(i) >> t.at(i);
  cin >> x;
  ll sum1,sum2 = 0;
  rep(i,n) sum1 += t.at(i);
  rep(i,n){
    sum2 += t.at(i);
    if(s.at(i) == x) break;
  }
  cout << sum1-sum2 << endl;
  return 0;
}
