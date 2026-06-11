#include<iostream>

using namespace std;

int main () {
  int N;
  cin >> N;
  bool OK =false;
  
  for (int a=1; a<10; a++) {
    for (int b=1; b<10; b++) {
      int total = a*b;
      if(total == N) OK = true;
    }
  }
  
  if (OK == false) cout << "No" << endl;
  else cout << "Yes" << endl;
}
      