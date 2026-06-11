#include <iostream>
using namespace std;

int main() {
  int input01;
  int input02;
  int input03;  

  cin >> input01 >> input02 >> input03;
  if(input01 < input02 && input02 < input03) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}