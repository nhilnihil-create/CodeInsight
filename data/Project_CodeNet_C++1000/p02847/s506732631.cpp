#include<iostream>
using namespace std;

int main() {
  string S;
  cin >> S;
  if (S == "SUN") {
    cout << 7;
  }
  else if (S == "MON") {
    cout << 6;
  }
  else if (S == "TUE") {
    cout << 5;
  }
  else if (S == "WED") {
    cout << 4;
  }
  else if (S == "THU") {
    cout << 3;
  }
  else if (S == "FRI") {
    cout << 2;
  }
  else {
    cout << 1;
  }
}