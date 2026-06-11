#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  
  int n = 0;
  for (int i=0 ; i<4 ; i++){
    for (int j=0 ; j<4 ; j++){
      if (s.at(i) == s.at(j))
        n++;
    }
  }
  
  if (n == 8)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}