#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    
  vector<int> vec(2);
  for (auto &i: vec) {
    cin >> i;
  }

  vector<int> vec2(vec[0]);
  for (auto &i: vec2) {
    cin >> i;
  }

  std::sort(vec2.begin(), vec2.end());
  
  int ans = 0;
  for(int i = 0; i< vec[1]; i++){
      ans += vec2[i];
  }
  
  cout << ans << endl;
   return 0;
}