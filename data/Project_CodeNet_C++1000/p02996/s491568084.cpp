#include <bits/stdc++.h>
using ll = long long;
using namespace std;
using Graph = vector<vector<ll>>;

int main(){
  int n; cin>>n;
  vector<pair<ll, ll>> ab(n);
  for (auto &&i : ab)
  {
    cin >> i.second >> i.first;
  }
  sort(ab.begin(), ab.end());
  ll tmpsum = 0;
  for (auto &&i : ab)
  {
    tmpsum += i.second;
    i.second = tmpsum;
  }
  for (auto &&i : ab)
  {
    if (i.second > i.first)
    {
      cout << "No" << endl;
      return 0;
    }
    
  }
  cout << "Yes" << endl;
  return 0;
  
}