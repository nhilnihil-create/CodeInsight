#include <iostream>
#include <string>

using namespace std;

int main() {
  int N;
  cin >> N;
  int p = N % 1000;
  if (p == 0){
    cout << 0 << endl;
  }
  else{
    cout << 1000 - p << endl;
  }
}