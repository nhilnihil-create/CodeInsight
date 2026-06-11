#include <iostream>
using namespace std;

int main() {
  double N;
  cin >> N;
  
  for(int i=0; i<=50000; i++) {
    int ibuff=i*1.08;
    if (N==ibuff) {
      cout << i << endl;
      return 0;
    }
  }
  cout << ":(" << endl;
  return 0;
}