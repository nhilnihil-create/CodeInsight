#include <bits/stdc++.h>
using namespace std;

int main() {
  int k,n; cin >> k >> n;
  
  vector<int> houses(n);
  for(int i = 0; i < n; i++) {
    cin >> houses.at(i);
  }
  
  int longest = 0;
  for(int i = 1; i <= n; i++) {
   int distance;
   if(i == n) {
     distance = k - houses.at(i-1) + houses.at(0);
   } else {
     distance = houses.at(i) - houses.at(i-1);
   }
    if(longest < distance) {
      longest = distance;
    }
  }
 
  cout << k - longest << endl;
  
  return 0; 
}