// ABC155 B - Papers, Please
#include <bits/stdc++.h>
using namespace std;
 
int main() {
  
  // 初期値
  int N, digit; 
  bool clearance = true;
  cin >> N;
  
  vector<int> papers(N);
  for (int i = 0; i < N; i++){
    cin >> papers.at(i);
  }
  
  // Main loop
  for (int i = 0; i < N; i++){
    digit = papers.at(i);
    
    if (digit % 2 == 0){
      if (digit % 3 == 0 || digit % 5 == 0){
        //
      } else {
        clearance = false;
        break;
      }
    }
  }
  
  if (clearance){
    cout << "APPROVED" << endl;
  } else {
    cout << "DENIED" << endl;
  }
  
  return 0;
}