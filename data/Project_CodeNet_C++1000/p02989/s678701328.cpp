#include <bits/stdc++.h>
using namespace std;

int main() {
 int num; cin >> num;
  
 vector<int> problems(num);
 for(int i = 0; i < num; i++) {
  cin >> problems.at(i);
 }
 std::stable_sort(problems.begin(), problems.end());
 
 int ans = problems.at(num/2) - problems.at((num/2)-1);
 
 cout << ans << endl;
  
  return 0; 
}
