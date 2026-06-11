#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#include <numeric>
using namespace std;

 int main() {
  int n;
  cin >> n;
  
  map<string,int> mp;
  rep(i,n) {
   string s;
   cin >> s;
   sort(s.begin(),s.end());
   mp[s]++;
   }
  
  long long count = 0;
  
  for(auto& p : mp) {
   int s = p.second;
   count += (long long)s*(s-1)/2;
   }
   cout << count;
  
  
 }