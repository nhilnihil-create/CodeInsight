#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <cmath>
using ll = long long;
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int main(){
  int n;
  cin >> n;
  map<string, int> x;
  rep(i, n){
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    auto itr = x.find(s);
    if (itr != x.end()) itr->second++;
    else x[s] = 1;
  }
  ll ans = 0;
  for (auto itr = x.begin(); itr != x.end(); itr++){
    ll n = itr->second;
    ans += n*(n-1)/2;
  }
  cout << ans << endl;
  
  return 0;
}