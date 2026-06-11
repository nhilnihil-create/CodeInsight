#include <bits/stdc++.h>
using namespace std;

int main() {
  
  string s, t;
  cin >> s >> t;
  
  int size = s.size();
  int size2 = t.size();
  
  int a = 0;
  for (int i = 0; i < size; i++){
    if(s.at(i) == t.at(i)){
      a = a + 1;
    }
  }
  
  if(a == size && size + 1 == size2){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }
  
   
  
  
}

