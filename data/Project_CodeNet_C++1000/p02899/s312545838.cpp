#include <bits/stdc++.h>
using namespace std;

int main() {
 int num; cin >> num;
 vector<int> ans(num);
  
 for(int i = 1; i <= num; i++) {
   int current;
   cin >> current;
   
   ans.at(current - 1) = i;
 }
 
 for(int i = 0; i < num; i++) {
  cout << ans.at(i) << " "; 
 }
  cout << endl;
 
  return 0;
}
