#include<bits/stdc++.h>

using namespace std;
using ll = long long;


bool cmp(pair<ll, ll> a, pair<ll, ll> b){
  return a.second < b.second;
}


int main(){
  ll n;
  cin >> n;
  vector<pair<ll, ll>> ab(n);
  for(int i=0; i<n; i++){
    cin >> ab[i].first >> ab[i].second;
  }
  sort(ab.begin(), ab.end(), cmp);
  
  
  bool flag = true;
  ll sum = 0;
  for(int i=0; i<n; i++){
    sum += ab[i].first;
    if(sum>ab[i].second) flag = false;
  }
  
  if(flag) cout << "Yes" << endl;
  else cout << "No" << endl;
  
  return 0;
}