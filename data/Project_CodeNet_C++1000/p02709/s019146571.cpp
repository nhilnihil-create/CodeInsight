#include <bits/stdc++.h>

using namespace std;

void max_self(long long& a , long long b){
  a = max(a , b);
}

int main() {
  int n ; cin>>n;
  vector<pair<long long, int> > v;
  for(int i = 0 ; i < n; ++i){
    long long x ; cin>>x;
    v.emplace_back(x , i);
  }
  sort(v.rbegin() , v.rend());
  vector<long long>dp(n + 1, -1000000009);
  dp[0] = 0;
  for(int i = 0 ; i < n; ++i){
    long long cst = v[i].first;
    int p = v[i].second;
    vector<long long> new_dp(n + 1 , -1000000009);
    for(int j = 0 ; j <= i; ++j){
      max_self(new_dp[j + 1] , dp[j] + abs(p - j)  * cst);
      max_self(new_dp[j] , dp[j] + abs(n - 1 - (i - j) - p) * cst);
    }
    swap(new_dp , dp);
  }
  cout<<*max_element(dp.begin() , dp.end())<<"\n";
}