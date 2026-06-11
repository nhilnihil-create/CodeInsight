// ABC168 A Therefore
#include <bits/stdc++.h>
using namespace std;
 
int main() {
  
  // 初期値
  int N;
  cin >> N;
  vector<string>  hon = {"pon", "pon", "hon", "bon", "hon", "hon", "pon", "hon", "pon", "hon"};
  
  //Main loop
  cout << hon.at(N % 10) << endl;

  return 0;
}