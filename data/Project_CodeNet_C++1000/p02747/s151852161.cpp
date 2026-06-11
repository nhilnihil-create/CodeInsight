#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string T;
  cin >> T;
  for (int i = 0; i < T.size(); i++) {
    if (i % 2 == 0){
      if (T.at(i) != 'h'){
        cout << "No" << endl;
        return 0;
      }
    }
    else {
      if (T.at(i) != 'i'){
        cout << "No" << endl;
        return 0;
      }
    }
  }
  
  if (T.at(T.size()-1) == 'h'){
    cout << "No" << endl;
    return 0;
  }
  cout << "Yes" << endl;
}
  

    
 
  
 
  