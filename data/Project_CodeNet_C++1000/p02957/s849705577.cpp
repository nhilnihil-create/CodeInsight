#include <bits/stdc++.h>
using namespace std;

int main(){
  long long A, B;
  cin >> A >> B;
  
  if (A - B >= 0){
    if ((A - B) % 2 == 0){
      cout << (A - B) / 2 + B << endl;
    }
    else{
      cout << "IMPOSSIBLE" << endl;
    }
  }
  else{
    if ((B - A) % 2 == 0){
      cout << (B - A) / 2 + A<< endl;
    }
    else{
      cout << "IMPOSSIBLE" << endl;
    }
  }
}