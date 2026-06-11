#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#include <numeric>
using namespace std;

 int main() {
  int n;
  cin >> n;
  
  vector<long long> h(n);
  rep(i,n) {
   cin >> h.at(i);
   }
   
   vector<int> a;
   
  int count = 0;
   rep(i,n - 1) {
    if(h.at(i) >= h.at(i + 1)) {
     count++;
     }
     else {
     a.push_back(count);
     count = 0;
      }
     }
     a.push_back(count);
     
     int ans = 0;
     for(int i = 0; i < a.size(); i++) {
     ans = max(ans,a.at(i));
      } 
      cout << ans;
 }