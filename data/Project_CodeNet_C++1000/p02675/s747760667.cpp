#include <bits/stdc++.h>
using namespace std;

int main() {
 string b;
  cin >> b;
  for (int i = 1; i < 4; i++){
  if(b.size() == i){
    if (b.at(i-1) == '2' || b.at(i-1) == '4' || b.at(i-1) == '5' || b.at(i-1) == '7' || b.at(i-1) == '9'){
      cout << "hon" << endl;
    }
    else if (b.at(i-1) == '0' || b.at(i-1) == '1' || b.at(i-1) == '6' || b.at(i-1) == '8'){
      cout << "pon" << endl;
    }
    else if (b.at(i-1) == '3'){
      cout << "bon" << endl;
    }
  }
}
}