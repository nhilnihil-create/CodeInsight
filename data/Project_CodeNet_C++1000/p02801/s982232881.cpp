#include <bits/stdc++.h>
using namespace std;

int main() {

  char c;
  cin >> c;
  
  vector<char> A = {'a','b','c','d','e','f','g','h','i',
                    'j','k','l','m','n','o','p','q','r',
                    's','t','u','v','w','x','y','z'};
  
  for(int i = 0; i < 26; i++) {
    if(c == A.at(i)) {
      cout << A.at(i+1) << endl;
      break;
    }
  }  
  
}