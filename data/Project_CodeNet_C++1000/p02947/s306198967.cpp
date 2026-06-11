#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int inf = 100100;

int main() {
  ll n;
  cin >> n;
  map<string,ll> m;
  for(ll i=0;i<n;i++){
    string s;
    cin >> s;
    sort(s.begin(),s.end());
    m[s]++;
  }
  
  ll cnt=0;
  for(auto x : m){
    auto value = x.second;
    if(value != 0){
	  cnt += value*(value-1)/2;
    }
  }
  
  cout << cnt << endl;
  return(0);
}