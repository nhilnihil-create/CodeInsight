#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<string,int>;
const double PI = acos(-1);
int main() {
ll n;
cin >> n;
map<string,ll> mp;
rep(i,n){
  string s;
  cin >> s;
  sort(s.begin(),s.end());
  mp[s]++;
}
ll ans = 0;
for(auto itr = mp.begin(); itr != mp.end(); itr++){
  ll x = itr->second;
 ans += x*(x-1)/2;
}
cout << ans << endl;
 
}