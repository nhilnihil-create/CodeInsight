#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#include <numeric>
using namespace std;

 int main() {
  int n;
  cin >> n;
  
  vector<int> b(n - 1);
  rep(i,n - 1) {
   cin >> b.at(i);
   }
   
   long long sum = b.at(0) * 2;
   for(int i = 1; i < n - 1; i++){
    sum += b.at(i);
    }
    
    for(int i = 0; i < n - 2; i++) {
     if(b.at(i) > b.at(i+1)) {
      sum = sum - (b.at(i) - b.at(i+1));
      }
      }
 cout << sum;
 }