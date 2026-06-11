#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int k;
  string s;
  cin >> k >> s;
  
  int size = s.size();
  if (k >= size){
    cout << s << endl;
  }
  else if (k < size){
    for (int i = 0; i < k; i++){
      cout << s.at(i);
    }
    cout << "..." << endl;
    
  }
  
  
}


