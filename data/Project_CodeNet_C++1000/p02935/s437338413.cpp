#include <bits/stdc++.h>
using namespace std;

int main() {
  int num; cin >> num;
  vector<double> elements(num);
  
  for(int i = 0; i < num; i++) {
    cin >> elements.at(i);
  }
  stable_sort(elements.begin(), elements.end());
  
  double ans = elements.at(0);
  for(int i = 1; i < num; i++) {
   ans = (ans + elements.at(i)) / 2;
  }
  
  cout << ans << endl;
    
  return 0; 
}