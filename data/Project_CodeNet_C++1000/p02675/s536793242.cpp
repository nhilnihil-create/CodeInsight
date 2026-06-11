#include <bits/stdc++.h>
using namespace std;

int main() {
  
  string s;
  cin >> s;
  int size = s.size() - 1;
  int x;
  char y = s.at(size);
  x = y - '0';
  if(x == 2 || x == 4 || x == 5 || x == 7 || x == 9){
    cout << "hon" << endl;
  }
  else if(x == 0 || x == 1 || x == 6 || x == 8){
    cout << "pon" << endl;
  }
  else{
    cout << "bon" << endl;
  }
  
  
}

